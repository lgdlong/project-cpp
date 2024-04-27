#include <bits/stdc++.h>
using namespace std;

struct user{
    string user_name;
    string phone_number;
};

int users_count = 0; // đếm mảng users tăng dần

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

void read_from_file(const string &filename, user *users) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Can not open file!"; return;
    }

    // tách tên ra
    string line;
    while (getline(file, line)) {
        users[users_count].user_name = extract_name(line);
        users[users_count].phone_number = extract_phone_number(line);
        users_count++;
    }
    file.close();
}

void print_users_name(user *users) {
    for (int i = 0; i < users_count; i++) {
        cout << users[i].user_name << ": " <<  users[i].phone_number << '\n';
    }
}

int main() {
    user users[1000]; // khai báo mảng users

    string filename = "data.txt";

    read_from_file(filename, users);
    print_users_name(users);
    
    return 0;
}

/*
- mot la user_name nam o dau hoac la khong. khong co chuyen user_name nam o giua



*/