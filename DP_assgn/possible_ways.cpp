#include <iostream>
#include <cmath>
using namespace std;

int checkRecursive(int x, int n, int curr_num = 1, int curr_sum = 0){
    int results = 0;

    int p = pow(curr_num, n);
    while (p + curr_sum < x) {
        results += checkRecursive(x, n, curr_num + 1, p + curr_sum);
                                  
        curr_num++;
        p = pow(curr_num, n);
    }
    
    if (p + curr_sum == x)
        results++;
    
    return results;
}


int main() {
    int a, b;
    cin >> a >> b;

    cout << checkRecursive(a, b);
}