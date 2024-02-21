#include "GPIO.h"
#include <thread> // For std::this_thread::sleep_for
#include <iostream>

int main()
{
    constexpr int gpioPin = 55; /* Specify your GPIO pin here */

    if (!GPIO::exportGPIO(gpioPin))
    {
        std::cerr << "Failed to export GPIO pin " << gpioPin << std::endl;
        return -1;
    }

    // Set GPIO direction to "out"
    if (!GPIO::setDirection(gpioPin, GPIO::Direction::OUT))
    {
        std::cerr << "Failed to set direction on GPIO pin " << gpioPin << std::endl;
        return -1;
    }
    std::cout << "success" <<std::endl;
    
    auto gpioValueFile = GPIO::openGPIOValueFile(gpioPin);
    while (true)
    {
        gpioValueFile << "1" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        gpioValueFile << "0" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    gpioValueFile.close();

    // Unexport GPIO pin
    GPIO::exportGPIO(gpioPin, true);
    return 0;
}
