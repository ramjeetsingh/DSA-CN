#include <iostream>
using namespace std;

int print(int n) {
    if (n == 1) {
        cout << 1 << ' ';
        return 2;
    }
    
    cout << print(n-1) << ' ';
    return n+1;
}

int main() {
    int n;
    cin >> n;

    print(n);
}
