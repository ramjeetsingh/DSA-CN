#include <iostream>
#include <vector>
using namespace std;


bool isPalindrome(string str){
    int len = str.length();
    for (int i = 0; i < len/2; i++ )
        if (str[i] != str[len-i-1])
            return false;

    return true;
}

bool isPalindromePair(vector<string> words) {
    if(words.size()==0){
        return false;
    }
    if(words.size()==1){
        return isPalindrome(words[0]);
    }
    for (int i = 0; i< words.size()-1; i++){
        for (int j = i+1; j< words.size() ; j++){
            string check_str="";

            check_str = words[i] + words[j];
            if (isPalindrome(check_str))
                return true;

            check_str = words[j] + words[i];
            if (isPalindrome(check_str))
                return true;

            check_str = words[j];
            if (isPalindrome(check_str))
                return true;

            check_str = words[i];
            if (isPalindrome(check_str))
                return true;
            }
    	}
    	return false;
    }


int main() {
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        string s;cin>>s;
        words[i]=s;
    }

    cout << (isPalindromePair(words) ? "true" : "false");
}