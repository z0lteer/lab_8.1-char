#include <iostream>
#include <cstring>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int find(const char* s) {
    const char* ptr = s;
    int dot_count = 0;

    while ((ptr = strchr(ptr, '.')) != nullptr) {
        dot_count++;
        if (dot_count == 3) {
            return ptr - s;
        }
        ptr++;
    }

    return -1;
}

char* change(char* s) {
    int len = strlen(s);
    for (int i = 3; i < len; i += 4) {
        s[i] = '.';
    }
    return s;
}

int main() {
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int third_dot_index = find(str);
    if (third_dot_index != -1)
        cout << "Index of third dot: " << third_dot_index << endl;
    else
        cout << "The string does not contain three dots." << endl;

    char* modified_str = change(str);
    cout << "Modified string (result): " << modified_str << endl;

    return 0;
}