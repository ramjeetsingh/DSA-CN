#include <bits/stdc++.h>

using namespace std;
int countWaysToMakeChange(int S[], int m, int n){
	int i, j, x, y; 

    int table[n + 1][m]; 
      
    for (i = 0; i < m; i++) {
        table[0][i] = 1; 
    }

    for (i = 1; i < n + 1; i++) { 
        for (j = 0; j < m; j++) { 
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0; 
 
            y = (j >= 1) ? table[i][j - 1] : 0; 

            table[i][j] = x + y; 
        } 
    } 
    
    return table[n][m - 1]; 

}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	int numDenominations;
    cin >> numDenominations;
	int* denominations = new int[numDenominations];
	for(int i = 0; i < numDenominations; i++){
	  cin >> denominations[i];
	}
	int value;
	cin >> value;
	cout << countWaysToMakeChange(denominations, numDenominations, value)<<endl;

	return 0 ; 
}