#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
        char data;
        TrieNode *children[26];

        bool isTerminal;

        TrieNode(char data)
        {
            this->data = data;
            for (int i = 0; i < 26; i++)
            {
                this->children[i] = NULL;
           }
           this->isTerminal = false;
        }
};

class Trie
{
    public:
        TrieNode *root;

        Trie()
        {
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode *root, string word)
        {
            // base condition
            if (word.length() == 0)
            {
                root->isTerminal = true;
                return ;
            }
            
            // find the index
            int index = word[0] - 'a';
            TrieNode *child;

            // if present
            if (root->children[index])
            {
                child = root->children[index];
            }

            // if absent
            else
            {
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            // recursive call
            insertUtil(child, word.substr(1));
        }

        void insertWord(string word)
        {
            insertUtil(root, word);
        }

        void printSuggestions (TrieNode *curr, vector<string> &temp, string prefix)
        {
            if (curr->isTerminal)
                temp.push_back(prefix);

            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                TrieNode *next = curr->children[ch - 'a'];

                if (next)
                {
                    prefix.push_back(ch);
                    printSuggestions(next, temp, prefix);
                    prefix.pop_back();
                }
            }
        }

        vector<vector<string>> getSuggestions(string word)
        {
            TrieNode *prev = root;
            string prefix = "";

            vector<vector<string>> output;

            for (int i = 0; i < word.length(); i++)
            {
                char lastCh = word[i];

                prefix.push_back(lastCh);

                // check for lastCh
                TrieNode *curr = prev->children[lastCh - 'a'];

                // if not found
                if (!curr)
                    break;

                // if found
                vector<string> temp;
                printSuggestions(curr, temp, prefix);

                output.push_back(temp);

                temp.clear();

                prev = curr;
            }

            return output;
        }
};

vector<vector<string>> phoneDirectory (vector<string> &contactList, string &queryStr)
{
    Trie *t = new Trie();

    for (int i = 0; i < contactList.size(); i++)
    {
        string str = contactList[i];
        t->insertWord(str);
    }

    return t->getSuggestions(queryStr);
}

int main()
{
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    cout << "Enter the elements of the contact list : "<<endl;

    vector<string> contactList(n);

    for (int i = 0; i < n; i++)
        cin >> contactList[i];

    string queryStr;
    cout << "Enter the query string : ";
    cin >> queryStr;

    cout << "Following are the suggestions : "<<endl;
    vector<vector<string>> output = phoneDirectory(contactList, queryStr);

    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}