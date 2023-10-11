#include <bits/stdc++.h>
using namespace std;

// 192.168.1.1
// 255.255.255.0

bitset<32> ipToBinary(const string& ipAddress) {
    vector<int> octets;
    stringstream ss(ipAddress);
    string octet;
    while (getline(ss, octet, '.')) {
        octets.push_back(stoi(octet));
    }

    bitset<32> binaryIp;
    int index = 0;
    for (int octet : octets) {
        for (int i = 7; i >= 0; --i) {
            binaryIp[index++] = (octet >> i) & 1;
        }
    }

    return binaryIp;
}

// Function to calculate net ID, host ID, and network address
void calculateNetAndHost(const string& ipAddress, const string& subnetMask) {
    // Convert IP address and subnet mask to binary
    bitset<32> ipBits = ipToBinary(ipAddress);
    bitset<32> maskBits = ipToBinary(subnetMask);

    // Calculate the network address by performing a bitwise AND operation
    bitset<32> networkBits = ipBits & maskBits;

    // Output the results
    cout << "IP Address: " << ipAddress << endl;
    cout << "Subnet Mask: " << subnetMask << endl;
    cout << "Network Address: ";
    
    for (int i = 0; i < 32; i += 8) {
        int octet = 0;
        for (int j = i; j < i + 8; ++j) {
            octet = (octet << 1) | networkBits[j];
        }
        cout << octet;
        if (i < 24) {
            cout << ".";
        }
    }
    
    cout << endl;

    cout << "Net ID: ";
    for (int i = 0; i < 32; i += 8) {
        int octet = 0;
        for (int j = i; j < i + 8; ++j) {
            octet = (octet << 1) | networkBits[j];
        }
        cout << octet;
        if (i < 24) {
            cout << ".";
        }
    }
    cout << endl;

    cout << "Host ID: ";
    for (int i = 0; i < 32; i += 8) {
        int octet = 0;
        for (int j = i; j < i + 8; ++j) {
            octet = (octet << 1) | (ipBits[j] & ~maskBits[j]);
        }
        cout << octet;
        if (i < 24) {
            cout << ".";
        }
    }
    cout << endl;
}

int main() {
    string ipAddress, subnetMask;

    cout << "Enter IP Address (dotted-decimal format, e.g., 192.168.1.1): ";
    cin >> ipAddress;
    cout << "Enter Subnet Mask (dotted-decimal format, e.g., 255.255.255.0): ";
    cin >> subnetMask;


    calculateNetAndHost(ipAddress, subnetMask);

    return 0;
}
