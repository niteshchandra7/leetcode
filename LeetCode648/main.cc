#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> lookUpTable;
    bool isEnd;
};

class Solution {
public:
    TrieNode* createTrieFromDict(vector<string>& dictionary) {
        TrieNode* dummy = new TrieNode();
        for (auto& word : dictionary) {
            updateTrie(word, dummy);
        }
        return dummy;
    }

    void updateTrie(string& word, TrieNode* dummy) {
        TrieNode* currNode = dummy;
        for (auto& letter : word) {
            auto& lut = currNode->lookUpTable;
            if (lut.find(letter) == lut.end()) {
                lut[letter] = new TrieNode();
            }
            currNode = lut[letter];
        }
        currNode->isEnd = true;
    }

    string replaceWord(string& word, TrieNode* dummy) {
        TrieNode* currNode = dummy;
        string ans = "";
        for (auto& letter : word) {
            auto& lut = currNode->lookUpTable;
            if (lut.find(letter) == lut.end()) {
                return word;
            }
            ans += letter;
            currNode = lut[letter];
            if (currNode->isEnd) {
                return ans;
            }
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* dummy = createTrieFromDict(dictionary);
        string ans = "";
        vector<string> words;
        string word = "";
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ') {
                words.push_back(word);
                word = "";
                continue;
            }
            word.push_back(sentence[i]);
        }
        words.push_back(word);
        for (auto& word : words) {
            ans += replaceWord(word, dummy);
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};