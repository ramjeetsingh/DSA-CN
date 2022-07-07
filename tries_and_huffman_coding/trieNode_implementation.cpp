#include <iostream>
using namespace std;

class trieNode {
    public:

    char data;
    trieNode ** children;
    bool isEnd;

    trieNode(char data) {
        this->data = data;

        children = new trieNode*[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }

        isEnd = false;
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
            root->isEnd = true;
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
        insertHelp(root, word);
        return;
    }

    bool searchHelp(trieNode* root, string word) {
        if (word.size() == 0) {
            if (root->isEnd) {
                return true;
            } else {
                return false;
            }
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


    void removeHelp(trieNode* root, string word) {
        if (word.length() == 0) {
            root->isEnd = false;
            return;
        }

        int index = word[0] - 'a';
        trieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return;
        }

        removeHelp(child, word.substr(1));

        if (child->isEnd == false) {
            for (int i = 0; i < 26; i++) {
                if (child->children[i] != NULL) {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }

    void remove(string word) {
        removeHelp(root, word);
    }
}; 