#include <iostream>
#include <string>
#include <sstream>

std::string intToBinary(int number, int numBits) {
    std::string binary = "";
    for (int i = numBits - 1; i >= 0; --i) {
        binary += ((number >> i) & 1) ? "1" : "0";
    }
    return binary;
}

std::string ipToBinary(const std::string& ip) {
    std::string binaryIP = "";
    std::istringstream ss(ip);  // Use stringstream for input parsing
    std::string octet;

    while (std::getline(ss, octet, '.')) {
        try {
            int octetValue = std::stoi(octet);

            // Check if the octet value is within the valid range (0-255)
            if (octetValue >= 0 && octetValue <= 255) {
                binaryIP += intToBinary(octetValue, 8);
                binaryIP += ".";
            } else {
                std::cerr << "Invalid IP address component: " << octet << std::endl;
                return "";
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid characters in IP address: " << octet << std::endl;
            return "";
        }
    }

    // Remove the trailing dot
    if (!binaryIP.empty()) {
        binaryIP.pop_back();
    }

    return binaryIP;
}

// Function to convert binary to dotted-decimal format
std::string binaryToDottedDecimal(const std::string& binary) {
    std::string dottedDecimal = "";
    for (int i = 0; i < 32; i += 8) {
        std::string octet = binary.substr(i, 8);
        int decimalValue = std::stoi(octet, nullptr, 2);
        dottedDecimal += std::to_string(decimalValue);
        if (i < 24) {
            dottedDecimal += ".";
        }
    }
    return dottedDecimal;
}

// Function to calculate subnet details
void calculateSubnet(const std::string& ip, int subnetSize) {
    // Convert the IP address to binary
    std::string binaryIP = ipToBinary(ip);

    // Calculate the subnet mask
    std::string subnetMask = binaryIP.substr(0, subnetSize) + std::string(32 - subnetSize, '0');

    // Convert subnet mask to dotted-decimal format
    std::string dottedSubnetMask = binaryToDottedDecimal(subnetMask);

    // Calculate the network address
    std::string networkAddress = binaryIP.substr(0, subnetSize) + std::string(32 - subnetSize, '0');

    // Convert network address to dotted-decimal format
    std::string dottedNetworkAddress = binaryToDottedDecimal(networkAddress);

    // Calculate the range of usable IP addresses
    std::string firstUsableIP = networkAddress.substr(0, 31) + "1";
    std::string lastUsableIP = networkAddress.substr(0, 31) + "0";
    lastUsableIP[31] = '1';

    // Convert usable IP addresses to dotted-decimal format
    std::string dottedFirstUsableIP = binaryToDottedDecimal(firstUsableIP);
    std::string dottedLastUsableIP = binaryToDottedDecimal(lastUsableIP);

    std::cout << "IP Address: " << ip << std::endl;
    std::cout << "Subnet Mask: " << dottedSubnetMask << std::endl;
    std::cout << "Network Address: " << dottedNetworkAddress << std::endl;
    std::cout << "First Usable IP: " << dottedFirstUsableIP << std::endl;
    std::cout << "Last Usable IP: " << dottedLastUsableIP << std::endl;
}

int main() {
    std::string ipAddress;
    int subnetSize;

    std::cout << "Enter an IP address (e.g., 192.168.1.1): ";
    std::cin >> ipAddress;

    std::cout << "Enter the subnet size (e.g., 24 for a /24 subnet): ";
    std::cin >> subnetSize;

    std::cout << "Input received - IP Address: " << ipAddress << ", Subnet Size: " << subnetSize << std::endl;

    calculateSubnet(ipAddress, subnetSize);

    return 0;
}