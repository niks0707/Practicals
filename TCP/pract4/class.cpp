// 192.168.1.1
// 124.25.45.1
// 242.5.1.2

#include <iostream>
#include <string>

using namespace std;

int main() {
    string ipAddress;
    cout << "Enter an IP address: ";
    cin >> ipAddress;

    int octet1 = 0, octet2 = 0, octet3 = 0, octet4 = 0;
    int octetsParsed = sscanf(ipAddress.c_str(), "%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);

    if (octetsParsed != 4 || octet1 < 0 || octet1 > 255 || octet2 < 0 || octet2 > 255 ||
        octet3 < 0 || octet3 > 255 || octet4 < 0 || octet4 > 255) {
        cout << "Invalid IP address format." << endl;
        return 1;
    }


    if (octet1 >= 1 && octet1 <= 126) {
        cout << "Class A IP address." << endl;
    } else if (octet1 >= 128 && octet1 <= 191) {
        cout << "Class B IP address." << endl;
    } else if (octet1 >= 192 && octet1 <= 223) {
        cout << "Class C IP address." << endl;
    } else if (octet1 >= 224 && octet1 <= 239) {
        cout << "Class D IP address (Multicast)." << endl;
    } else if (octet1 >= 240 && octet1 <= 255) {
        cout << "Class E IP address (Reserved)." << endl;
    } else {
        cout << "Invalid IP address." << endl;
    }

    return 0;
}
