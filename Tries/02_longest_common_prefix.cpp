#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
        char data;
        TrieNode *children[26];
        bool isTerminal;
        int childrenCount;
    
        TrieNode(char ch)
        {
            data = ch;
            for (int i = 0; i < 26; i++)
            {
                children[i] = NULL;
            }
            isTerminal = false;
            childrenCount = 0;
        }
};

class Trie
{
    public:
        TrieNode *root;
        
        Trie(char ch)
        {
            root = new TrieNode(ch);
        }
    
        void insertUtil(TrieNode* node, string word)
        {
            // base case
            if (word.length() == 0)
            {
                root->isTerminal = true;
                return ;
            }

            // assumption, word will be in lower case
            int index = word[0] - 'a';
            TrieNode* child;

            // present
            if (root->children[index])
                child = root->children[index];

            // absent
            else
            {
                child = new TrieNode(word[0]);
                root-> children[index] = child;
                root->childrenCount++;
            }

            // Recursive callse
            insertUtil(child, word.substr(1)); 
        }

        void insertWord(string word)
        {
            insertUtil(root, word);
        }
    
        void lowestCommonPrefix(string word, string &ans)
        {
            for (int i = 0; i < word.length(); i++)
            {
                char ch = word[i];
                
                if (root->childrenCount == 1)
                {
                    ans.push_back(ch);
                    // move to next element 
                    int index = ch - 'a';
                    root = root->children[index];
                }
                else
                    break;
                
                if (root->isTerminal)
                    break;
            }
        }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie* t = new Trie('\0');
    
    for (int i = 0; i < n; i++)
        t->insertWord(arr[i]);
    
    string ans = "";
    string firstWord = arr[0];
    t->lowestCommonPrefix(firstWord, ans);
    return ans;
}

int main()
{
    vector<string> arr{"coding", "codezen", "codingninja", "coder"};
    string ans = longestCommonPrefix(arr, 4);

    cout << ans;
    return 0;
}