#include <bits/stdc++.h>
using namespace std;


int main() {
    string str = "akw:a 0776506822oaw";
    size_t first = str.find('0');

    string a = extract_phone_number(str);

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