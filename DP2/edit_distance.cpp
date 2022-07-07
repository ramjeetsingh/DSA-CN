#include <iostream>
#include <cmath>
using namespace std;

int editDP(string s, string t) {
    int m = s.length();
    int n = t.length();

    int **ans = new int*[m+1];
    for (int i = 0; i <= m; i++) {
        ans[i] = new int[n+1];
        for (int j = 0; j <= n; j++) {
            ans[i][j] = -1;
        }
    }

    for (int row = 0; row <= m; row++) {
        ans[row][0] = row;
    }
    for (int col =0; col <= n; col++) {
        ans[0][col] = col;
    }

    for (int row = 1; row <= m; row++) {
        for (int col = 1; col <= n; col++) {
            if (s[m-row] == t[n-col]) {
                ans[row][col] = ans[row-1][col-1];
            }
            else {
                int x = ans[row-1][col];
                int y = ans[row-1][col-1];
                int z = ans[row][col-1];

                ans[row][col] = min(x, min(y, z)) + 1;
            }
        }
    }

    return ans[m][n];
}


int edit_mem_help(string s, string t, int **ans) {
    int m = s.length();
    int n = t.length();

    if (s.length() == 0 || t.length() == 0) {
        return max(s.length(), t.length());
    }

    if (ans[m][n] != -1) {
        return ans[m][n];
    }

    int res;
    if (s[0] == t[0]) {
        res = edit_mem_help(s.substr(1), t.substr(1), ans);
    }
    else {
        int x = edit_mem_help(s.substr(1), t, ans);           //insert
        int y = edit_mem_help(s, t.substr(1), ans);           //delete
        int z = edit_mem_help(s.substr(1), t.substr(1), ans); //update

        res = min(x, min(y, z))+1;
    }

    ans[m][n] = res;
    return ans[m][n];
}

int edit_mem(string s, string t) {
    int m = s.length();
    int n = t.length();

    int **output = new int*[m+1];
    for (int i = 0; i <= m; i++) {
        output[i] = new int[n+1];
        for (int j = 0; j <= n; j++) {
            output[i][j] = -1;
        }
    }

    return edit_mem_help(s, t, output);
}




int edit(string s, string t) {
    if (s.length() == 0 || t.length() == 0) {
        return max(s.length(), t.length());
    }

    if (s[0] == t[0]) {
        return edit(s.substr(1), t.substr(1));
    }

    int x = edit(s.substr(1), t);           //insert
    int y = edit(s, t.substr(1));           //delete
    int z = edit(s.substr(1), t.substr(1)); //update

    return min(x, min(y, z))+1;
}

int main() {
    string s, t;
    cin >> s >> t;

    cout << edit_mem(s, t);
}