// 11000000101010000000000100000001

#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
#include <iomanip>

std::string binaryToDottedDecimal(const std::string& binaryIP) {
    std::string decimalIP;
    for (int i = 0; i < 32; i += 8) {
        std::bitset<8> octet(binaryIP.substr(i, 8));
        decimalIP += std::to_string(octet.to_ulong());
        if (i < 24) {
            decimalIP += ".";
        }
    }
    return decimalIP;
}

std::string binaryToHexadecimal(const std::string& binaryIP) {
    std::ostringstream hexStream;
    for (int i = 0; i < 32; i += 8) {
        std::bitset<8> octet(binaryIP.substr(i, 8));
        hexStream << std::uppercase << std::hex << std::setfill('0') << std::setw(2) << octet.to_ulong();
        if (i < 24) {
            hexStream << ":";
        }
    }
    return hexStream.str();
}

int main() {
    std::string binaryIP;
    std::cout << "Enter IP address in binary notation (32 bits): ";
    std::cin >> binaryIP;

    if (binaryIP.length() != 32) {
        std::cout << "Invalid input. Please enter a valid 32-bit binary IP address." << std::endl;
    } else {
        std::string dottedDecimalIP = binaryToDottedDecimal(binaryIP);
        std::string hexIP = binaryToHexadecimal(binaryIP);

        std::cout << "Dotted Decimal Notation: " << dottedDecimalIP << std::endl;
        std::cout << "Hexadecimal Notation: " << hexIP << std::endl;
    }

    return 0;
}