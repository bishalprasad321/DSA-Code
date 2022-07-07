#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char data);
};

TrieNode :: TrieNode(char data)
{
    this->data = data;

    for (int i = 0; i < 26; i++)
    {
        children[i] = NULL;
    }

    this->isTerminal = false;
}

class Trie
{
    public:
        TrieNode* root;

        Trie()
        {
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* node, string word)
        {
            // base case
            if (word.length() == 0)
            {
                root->isTerminal = true;
                return ;
            }

            // assumption, word will be in caps
            int index = word[0] - 'A';
            TrieNode* child;

            // present
            if (root->children[index])
                child = root->children[index];

            // absent
            else
            {
                child = new TrieNode(word[0]);
                root-> children[index] = child;
            }

            // Recursive callse
            insertUtil(child, word.substr(1)); 
        }

        void insertWord(string word)
        {
            insertUtil(root, word);
        }

        bool searchUtil(TrieNode* node, string word)
        {
            // base case
            if (word.length() == 0)
                return root->isTerminal;
            
            // assumption, word will be in caps
            int index = word[0] - 'A';
            TrieNode *child;

            // present
            if (root->children[index])
                child = root->children[index];

            // absent
            else
            {
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            // recursive call
            return searchUtil(child, word.substr(1));
        }

        bool searchWord(string word)
        {
            return searchUtil(root, word);   
        }

        void removeUtil(TrieNode* node, string word)
        {
            // base case 
            if (word.length() == 0)
            {
                root->isTerminal = !root->isTerminal;
                return ;
            }
            
            // assumption , word will be in caps
            int index = word[0] - 'A';
            TrieNode* child;

            // for present case
            if (root->children[index])
                child = root->children[index];
            
            // for absent case
            else
            {
                child = new TrieNode(word[0]);
                root-> children[index] = child;
            }

            // recursive call
            removeUtil(child, word.substr(1));
        }

        void removeWord(string word)
        {
            removeUtil(root, word);
        } 
};

int main()
{
    Trie* t = new Trie();

    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");

    string insert;
    cout << "Enter a word to insert into the trie (Enter in CAPS) : ";
    cin >> insert;

    t->insertWord(insert);

    cout << "Inserted successfully!!" << endl;

    string search;
    cout << "Enter the word to search : ";
    cin >> search;

    if (t->searchWord(search))
        cout << "The word "<< search << " is present!!"<<endl;

    else
        cout << "The word "<< search << " is absent in the trie!!"<<endl;

    string remove;
    cout << "Enter a word to remove from the trie : ";

    cin >> remove;
    t->removeWord(remove);

    cout << remove <<" removed successfully!!"<<endl;
    
    return 0;
}