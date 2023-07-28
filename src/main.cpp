#include "core/Framework.h"

/**
 * @brief The program's main entry point.
 * @return 0 if the the framework initialized successfully, 1 if not.
 */
int main()
{
    // Instantiate the engine framework
    Framework framework;

    // Initialize the Framework.
//    if (!framework.init()) {
//        std::cout << "ERROR: Unable to initialize the Framework." << std::endl;
//        return 1;
//    }

    // The game loop. A continous while loop until the game ends.
    framework.gameLoop();

    return 0;
}
