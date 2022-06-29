#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int> hashMap;
    // map<string, int> hashMap;
    
    // insertion

    // method 1 : by making a pair using make_pair() function
    pair<string, int> tmp = make_pair("Hello", 5);
    hashMap.insert(tmp);

    // method 2 : by making pair
    pair<string, int> tmp2("Hola", 7);
    hashMap.insert(tmp2);

    // method 3 : using key value method

    // case 01 : insertion
    hashMap["World"] = 1;

    // case 02: updation of existing value at key
    hashMap["World"] = 2;

    // to check the value for any key(method 1)
    cout << hashMap["World"] << endl;

    // to check the value for any key(method 2)
    cout << hashMap.at("Hello") << endl;

    // Size of hashMap
    cout << hashMap.size() <<endl;

    // erase function
    hashMap.erase("World");
    cout << hashMap.size() << endl;

    // iterator
    unordered_map<string, int>::iterator it = hashMap.begin();
    // map<string, int>::iterator it = hashMap.begin();

    while (it != hashMap.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}