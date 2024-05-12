#include <iostream>
#include <vector>
#include <string>

#include "problem8.h"

using namespace std;

bool is_valid_part(const string& part) {
    if (part.empty() || part.size() > 3 || (part.size() > 1 && part[0] == '0')) {
        return false;
    }
    int num = stoi(part);
    return num >= 0 && num <= 255;
}

void generate_IPs(const string& s, int start, int parts, string current, vector<string>& result) {
    if (parts == 4 && start == s.size()) {
        result.push_back(current);
        return;
    }

    for (int i = 1; i <= 3 && start + i <= s.size(); ++i) {
        string part = s.substr(start, i);
        if (is_valid_part(part)) {
            if (parts > 0) {
                part = "." + part;
            }
            generate_IPs(s, start + i, parts + 1, current + part, result);
        }
    }
}

vector<string> genIp(const string& s) {
    vector<string> result;
    generate_IPs(s, 0, 0, "", result);
    return result;
}

void p8_main(void) {
    string s = "25525511135";
    vector<string> ips = genIp(s);
    for (const string& ip : ips) {
        cout << ip << endl;
    }
}
