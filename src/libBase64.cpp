#include <iostream>
#include <string>
#include <vector>
#include "libBase64.h"

using namespace std;

const string Base64Table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

string getBinary(int N, int cNum) {
    unsigned int i;
    string res;
    i = 1 << (cNum - 1);
    while (i != 0) {
        if (N & i) { res += '1'; }
        else res += '0';
        i >>= 1;
    }
    return res;
}

vector<int> getDecodingIndex(string line) {
    int cNum = 8;
    int count = line.length() / cNum;
    bool flag = false;
    if (count * cNum != line.length()) {
        count += 1;
        flag = true;
    }
    vector<int> indexes(count);
    for (int i = 0; i < count; ++i) {
        if ((i == count - 1) && flag) {
            string buf;
            buf += line.substr(0, line.length() % cNum);
            buf.append(cNum - line.length() % cNum, '0');
            indexes[i] = strtol(buf.c_str(), nullptr, 2);
        } else {
            indexes[i] = strtol(line.substr(0, cNum).c_str(), nullptr, 2);
        }
        line.erase(0, cNum);
    }
    return indexes;
}

vector<int> getEncodingIndex(string line) {
    int cNum = 6;
    int count = line.length() / cNum;
    bool flag = false;
    if (count * cNum != line.length()) {
        count += 1;
        flag = true;
    }
    vector<int> indexes(count);
    for (int i = 0; i < count; ++i) {
        if ((i == count - 1) && flag) {
            string buf;
            buf += line.substr(0, line.length() % cNum);
            buf.append(cNum - line.length() % cNum, '0');
            indexes[i] = strtol(buf.c_str(), nullptr, 2);
        } else {
            indexes[i] = strtol(line.substr(0, cNum).c_str(), nullptr, 2);
        }
        line.erase(0, cNum);
    }
    return indexes;
}

string decodingBase64(const string &line) {
    int cNum = 6;
    string binaryRepresentation;
    string res;
    for (char c:line) {
        int index;
        index = Base64Table.find(c);
        binaryRepresentation += getBinary(index, cNum);
    }
    vector<int> indexes = getDecodingIndex(binaryRepresentation);
    for (int i:indexes) {
        res += (char) (i);
    }
    return res;
}

string encodingBase64(const string &line) {
    int cNum = 8;
    string binaryRepresentation;
    string res;
    for (char c:line) {
        int index = (int) (c);
        binaryRepresentation += getBinary(index, cNum);
    }
    vector<int> indexes = getEncodingIndex(binaryRepresentation);
    for (int i:indexes) {
        res += Base64Table[i];
    }
    return res;
}
