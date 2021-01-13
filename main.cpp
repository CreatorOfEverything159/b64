#include <iostream>
#include "libBase64.h"

using namespace std;

int main() {
    string line;

    cout << "Enter message to encode: ";
    getline(cin, line);
    cout << encodingBase64(line);
    cout << endl;
    cout << endl;

    cout << "Enter message to decode: ";
    getline(cin, line);
    cout << decodingBase64(line);
    cout << endl;
}
