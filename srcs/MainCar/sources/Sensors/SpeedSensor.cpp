/**
 * @file SpeedSensor.cpp
 * @brief Implementation of the SpeedSensor class that reads speed data from a CAN bus.
 */

#include "SpeedSensor.hpp"

/**
 * @brief Constructs a SpeedSensor object.
 *
 * @param can Reference to a CANBus object.
 * @param id The CAN identifier for the speed sensor.
 */
SpeedSensor::SpeedSensor(CANBus& can, uint32_t id) : ISensor(can, id), _lastSpeed(0) {
    initialize();
}

/**
 * @brief Initializes the speed sensor.
 */
void SpeedSensor::initialize() {
    // Output initialization message to the console
    std::cout << "Initializing speed sensor..." << std::endl;
}

/**
 * @brief Reads data from the CAN bus for the speed sensor.
 *
 * @return 0 if data is successfully read and processed, -1 otherwise.
 */
int SpeedSensor::readData() {
    uint32_t id; // Variable to hold the CAN message ID
    std::vector<uint8_t> data; // Vector to hold the CAN message data

    // Check if a message is received from the CAN bus
    if (canBus.receiveMessage(id, data)) {
        std::cout << "Id: " << id << "\ncanId: " << canId << std::endl;
        // Check if the received message ID matches the sensor's CAN ID
        if (id == canId) {
            // Output the received message ID and data to the console
            std::cout << "Message received with ID: 0x"
                      << std::hex << id << std::dec << "\nData: ";

            // Print each byte of the received data
            for (size_t i = 0; i < data.size(); ++i) {
                std::cout << "0x" << std::hex << (int)data[i] << " ";
            }

            std::cout << std::dec << std::endl;

            // Ensure there are at least 2 bytes of data to interpret the speed value
            if (data.size() >= 2) {
                // Combine the first two bytes to form the speed value
                int sensorValue = data[0] | (data[1] << 8);
                _lastSpeed = sensorValue; // Update the last speed value

                // Output the speed value to the console
                std::cout << "Speed from speed sensor class: " << _lastSpeed << std::endl;

                return 0; // Indicate success
            } else {
                // Error: Not enough data to interpret the speed value
                std::cerr << "Error: Insufficient data to interpret the speed value." << std::endl;
                return -1; // Indicate failure
            }
        } else {
            // Ignore messages with unexpected IDs
            std::cout << "Message ignored with unexpected ID: 0x"
                      << std::hex << id << std::dec << std::endl;
            return -1; // Indicate failure
        }
    } else {
        // No message available on the CAN bus
        std::cout << "No message available on the CAN bus." << std::endl;
        return -1; // Indicate failure
    }
}

/**
 * @brief Gets the last speed value read by the sensor.
 *
 * @return The last speed value.
 */
const int SpeedSensor::getValue() const {
    return _lastSpeed;
}

/**
 * @brief Gets the type of the sensor as a string.
 *
 * @return The sensor type, "SpeedSensor".
 */
const std::string SpeedSensor::getType() const {
    return "SpeedSensor";
}
