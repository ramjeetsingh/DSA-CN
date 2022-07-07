#include <iostream>
using namespace std;

int countWays(int n) {
	int res[n+1];
	res[0] = 1;
	res[1] = 1;
	
	for(int i = 2; i <= n; i++)
	{
	res[i] = 0;
		
	for(int j = 1; j <= 3 && j <= i; j++)
		res[i] += res[i - j];
	}
	return res[n];
}

int main() {
	int n;
    cin >> n;
	
	cout << countWays(n);
}
