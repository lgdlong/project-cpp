#include <bits/stdc++.h>
using namespace std;

bool check_colon(string str) {
    if (str.find(':') == string::npos) return false;
    else return true;
}   

string extract_phone_number(string str) {
    size_t pos_of_first_zero = str.find('0'); // vị trí bắt đâu số điện thoại

    if (pos_of_first_zero == string::npos) return "";

    size_t end_pos_of_phone_num = pos_of_first_zero;
    for (size_t i = pos_of_first_zero; i < str.length(); i++) {
        if (!isdigit(str[i+1]) || str[i+1] == '\0') {
            end_pos_of_phone_num = i;
            break;
        }
    }

    if (end_pos_of_phone_num == pos_of_first_zero) return "";
    
    size_t length_phone_num = end_pos_of_phone_num - pos_of_first_zero + 1;

    string phone_num = str.substr(pos_of_first_zero, length_phone_num);
    
    if (length_phone_num == 10) return phone_num;
    else return "";
}

string extract_name(string str) {
    size_t pos = str.find(':');
    string beforeColon;
    if (check_colon(str)) {
        beforeColon = str.substr(0, pos);
    }
    
    return beforeColon;
}


int main() {
    string str = "userE:01224264432";
    size_t first = str.find('0');
    string a = extract_name(str);
    a+= ": ";
    a += extract_phone_number(str);

    cout << a;

    // cout << extract_phone_number(str);
    return 0;
}

/*
akw:a 0776 5 0 6 8 2 2
12345678910111213141516
vị trí đầu: 6
vị trí cuối: 15
*/