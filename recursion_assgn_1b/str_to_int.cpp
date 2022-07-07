#include <iostream>
using namespace std;

#include <cstring>
#include <math.h>

void convert(char str[], int len, int& ans) {
    if (len == 0) {
        return;
    }

    int dig = str[0] - '0';

    ans += ((pow(10, len-1))*dig);

    convert(str+1, len-1, ans);
}


int main() {
    char str[100];
    cin.getline(str, 100);

    int l = strlen(str);
    int ans = 0;

    convert(str, l, ans);
    cout << ans;
}