#include <iostream>
#include <vector>
#include <unordered_set>

#include "problem9.h"

using namespace std;

// Trie Node
struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

// Trie Class
class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    TrieNode* getRoot() {
        return root;
    }

private:
    TrieNode* root;
};

void findWordsUtil(vector<vector<char>>& board, int row, int col, TrieNode* root, string current, unordered_set<string>& result, vector<vector<bool>>& visited) {
    int rows = board.size();
    int cols = board[0].size();

    if (row < 0 || row >= rows || col < 0 || col >= cols || visited[row][col]) {
        return;
    }

    int index = board[row][col] - 'a';
    if (!root->children[index]) {
        return;
    }

    current += board[row][col];
    TrieNode* nextNode = root->children[index];

    if (nextNode->isEnd) {
        result.insert(current);
    }

    visited[row][col] = true;

    int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for (int i = 0; i < 8; ++i) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];
        findWordsUtil(board, newRow, newCol, nextNode, current, result, visited);
    }

    visited[row][col] = false;
}

unordered_set<string> findWords(vector<vector<char>>& board, Trie* trie) {
    unordered_set<string> result;
    int rows = board.size();
    int cols = board[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    TrieNode* root = trie->getRoot();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            findWordsUtil(board, i, j, root, "", result, visited);
        }
    }

    return result;
}

void p9_main(void) {
    // Example usage
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };

    vector<string> words = { "oath", "pea", "eat", "rain" };

    Trie* trie = new Trie();
    for (const string& word : words) {
        trie->insert(word);
    }

    unordered_set<string> foundWords = findWords(board, trie);

    for (const string& word : foundWords) {
        cout << word << " ";
    }
}
