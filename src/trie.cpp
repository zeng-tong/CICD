// 
// Created by tong zeng on 2018/7/4 5:43 PM.
//
#include <utility>
#include "commonHeader"

class Trie {
public:
    Trie() {
        root = new TreeNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.empty())
            return;
        auto current = root;
        for (auto chr: word) {
            if (current->children[chr - 'a'] == nullptr) current->children[chr - 'a'] = new TreeNode();
            current = current->children[chr - 'a'];
        }
        current->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto res = beginWith(std::move(word));
        return res != root && res->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return beginWith(std::move(prefix)) != root;
    }

private:
    struct TreeNode {
        bool isWord;
        vector<TreeNode *> children;

        TreeNode() : isWord(false), children(vector<TreeNode *>(26, nullptr)) {}
    };

    TreeNode *root;

    TreeNode *beginWith(string prefix) {
        auto current = root;
        for (auto chr: prefix) {
            if (current->children[chr - 'a'] == nullptr) return root;
            current = current->children[chr - 'a'];
        }
        return current;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
int main() {
    Trie *obj = new Trie();
    obj->insert("hello");
    cout << obj->search("hello") << endl;
    cout << obj->search("hell") << endl;
    cout << obj->startsWith("hello") << endl;
    return 0;
}