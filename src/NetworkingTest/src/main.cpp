#include <iostream>
#include <chrono>

// This is only for asio
#ifdef _WIN32
#define _WIN32_WINNT 0X0A00
#endif
#define ASIO_STANDALONE

#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

std::vector<char> vBuffer(1 * 1024);

/**
 * @brief Grab data from the socket
 * @param socket Socket the read from
*/
void GrabSomeData(asio::ip::tcp::socket& socket)
{
	/*
	* When the socket gets data from the server, we don't know how much the
	* server will spit out. Therefore, we don't know how long we must wait
	* to receive the full message. We create a lambda function that keeps
	* reading data until the socket gives us an error.
	*/
	socket.async_read_some(asio::buffer(vBuffer.data(), vBuffer.size()),
		[&](std::error_code ec, std::size_t length)
		{
			if (!ec)
			{
				std::cout << "\n\nRead " << length << "bytes\n\n";

				for (const auto b : vBuffer)
					std::cout << b;

				GrabSomeData(socket);
			}
		}
	);
}

void forceDelay()
{
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(20000ms);
}

int main()
{
	asio::error_code ec;

	// Create platform specific interface
	asio::io_context context;

	// Give some fake tasks to asio so the context doesn't finish
	asio::io_context::work idleWork(context);

	// Start the context
	std::thread thrContext = std::thread([&]() { context.run(); });

	// Get the endpoint address at destination
	asio::ip::tcp::endpoint endpoint(asio::ip::make_address("192.168.68.1", ec), 80);

	// Create socket
	asio::ip::tcp::socket socket(context);

	// Tell socket to try and connect
	socket.connect(endpoint, ec);
	
	// Check if we successfully connected to the server
	if (!ec)
	{
		std::cout << "Connected!" << std::endl;
	}
	else
	{
		std::cout << "Failed to connect to the address:\n" << ec.message() << std::endl;
	}

	if (socket.is_open())
	{
		GrabSomeData(socket);

		// Send we request to the server
		std::string sRequest =
			"GET /index.html HTTP/1.1\r\n"
			"Host: example.com\r\n"
			"Connection: close\r\n\r\n";

		socket.write_some(asio::buffer(sRequest.data(), sRequest.size()), ec);
		
		forceDelay();
	}

	return 0;
}