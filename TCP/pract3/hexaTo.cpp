// C0:A8:01:01

#include <bits/stdc++.h>
using namespace std;

// Convert a hexadecimal string to an integer
int hexToDecimal(const std::string &hex) {
    std::stringstream ss;
    ss << std::hex << hex;
    int decimal;
    ss >> decimal;
    return decimal;
}

// Convert an integer to binary string
string decimalToBinary(int decimal) {
    string binary;
    while (decimal > 0) {
        binary = (decimal % 2 == 0 ? "0" : "1") + binary;
        decimal /= 2;
    }
    // Pad with zeros to make it 8 bits
    while (binary.length() < 8) {
        binary = "0" + binary;
    }
    return binary;
}

int main() {
    cout<<"Enter Hexadecimal IP address: ";
    string hexIP = "";
    cin>>hexIP;
    istringstream hexStream(hexIP);
    string segment;
    vector<int> decimals;


    while (std::getline(hexStream, segment, ':')) {
        decimals.push_back(hexToDecimal(segment));
    }

   
    std::cout << "Decimal Dotted IP: ";
    for (size_t i = 0; i < decimals.size(); ++i) {
        std::cout << decimals[i];
        if (i < decimals.size() - 1) {
            std::cout << ".";
        }
    }
    std::cout << std::endl;

    // Convert and print binary IP
    std::cout << "Binary IP: ";
    for (size_t i = 0; i < decimals.size(); ++i) {
        std::cout << decimalToBinary(decimals[i]);
        if (i < decimals.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
