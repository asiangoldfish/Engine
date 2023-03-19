#pragma once

namespace Network
{
	namespace Message
	{
		/**
		 * @brief Message header
		 * The headeris sent at start of all messages. The template allows us
		 * to use "enum class" to ensure that the messages are valid at compile
		 * time
		 * 
		 * @tparam T enum class of choice
		*/
		template <typename T>
		struct MessageHeader
		{
			T id{}:
			uint32_t size = 0;
		};

		template <typename T>
		struct Message
		{
			MessageHeader<T> header{};
			std::vector<uint8_t> body;

			// Returns size of entire Message packet in bytes
			size_t size() const
			{
				return sizeof(MessageHeader<T>) + body.size();
			}

			// Override for std::cout compatibility - produces friendly
			// description of Message
			friend std::ostream& operator << (std::ostream& os, const Message<T>& msg)
			{
				os << "ID" << int(msg.header.id) << " Size:" << msg.header.size;
				return os;
			}

			// Pushes any POD-liek data into the Message buffer
			template<typename Datatype>
			friend Message<T>& operator << (Message<T>& msg, const DataType& data)
			{
				// Check that the type of the data being pushed is trivially copyable
				static_assert(std::is_standard_layout<DataType>::value, "Data is too complex to be pushed into the vector");

				// Cache current size of vector, as this will be the point we insert the data
				size_t i = msg.body.size();

				// Resize the vector by the size of the data beingn pushed
				msg.body.resize(msg.body.size() + sizeof(DataType);

				// Physically copy the data into the newly allocated vector space
				std::memcpy(msg.body.data() + i, &data, sizeof(DataType));

				// Recalculate the message size
				msg.header.size = msg.size();

				return msg;
			}
		};
	}
}