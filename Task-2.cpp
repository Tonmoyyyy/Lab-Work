#include <iostream>
using namespace std;

void encode(string &s, int j) {
    for (int i = j; i < s.length(); i++) {
        s[i] += 3;
    }
}

void decode(string &s, int j) {
    for (int i = j; i < s.length(); i++) {
        s[i] -= 3;
    }
}

int main() {
    string in;
    int j;

    cout << "Enter a string: ";
    cin >> in;

    cout << "Enter an integer j: ";
    cin >> j;

    encode(in, j);
    cout << "Encoded string: " << in << endl;

    decode(in, j);
    cout << "Decoded string: " << in << endl;

    return 0;
}
