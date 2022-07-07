#include <iostream>
using namespace std;

int subseq(string input, string output[]) {
    if (input.size() == 0) {
        output[0] = "";
        return 1;
    }

    string smallInput = input.substr(1);
    int smallOutput = subseq(smallInput, output);

    for (int i = 0; i < smallOutput; i++) {
        output[i+smallOutput] = input[0] + output[i];
    }

    return 2*smallOutput;
}


int main() {
    string s;
    cin >> s;

    string output[100];

    int size = subseq(s, output);
    for (int i = 0; i < size; i++) {
        cout << output[i] << endl;
    }
}