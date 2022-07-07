#include <iostream>
using namespace std;

class trieNode {
    public:

    char data;
    trieNode ** children;

    trieNode(char data) {
        this->data = data;

        children = new trieNode*[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class trie {
    trieNode* root;

    public:

    trie() {
        root = new trieNode('\0');
    }

    void insertHelp(trieNode* root, string word) {
        if (word.size() == 0) {
            return;
        }

        int index = word[0] - 'a';   // index of word[0]

        trieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new trieNode(word[0]);
            root->children[index] = child;
        }

        insertHelp(child, word.substr(1));
        return;
    }

    void insert(string word) {
        if (search(word)) {
            return;
        }

        insertHelp(root, word);
        return;
    }

    bool searchHelp(trieNode* root, string word) {
        if (word.size() == 0) {
            return true;
        }

        int index = word[0] - 'a';

        if (root->children[index] == NULL) {
            return false;
        }

        trieNode* child = root->children[index];

        return searchHelp(child, word.substr(1));
    }

    bool search(string word) {
        return searchHelp(root, word);
    }

    void completeHelp(trieNode* root, string word, string origWord) {
        if (word.size() == 0) {
            for (int i = 0; i < 26; i++) {
                if (root->children[i] != NULL) {
                    cout << origWord << root->children[i]->data << endl;
                    completeHelp(root->children[i], word, origWord+root->children[i]->data);
                }
            }
            return;
        }

        int index = word[0] - 'a';
        trieNode* child = root->children[index];
        completeHelp(child, word.substr(1), origWord);
        return;
    }

    void complete(string word) {
        completeHelp(root, word, word);
    }

}; 


int main() {
    int n;
    cin >> n;

    trie t;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;

        while (word.size() > 0) {
            t.insert(word);
            word = word.substr(1);
        }
    }

    string word;
    cin >> word;

    if (!t.search(word)) {
        cout << "No possible word present" << endl;
    } else {
        cout << word << endl;
        t.complete(word);
    }
}