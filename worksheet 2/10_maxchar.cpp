#include <iostream>
#include <string> 
#include <cstring>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
	string s, s1;
	
    cout << "Enter string" << endl;
	getline(cin, s);
    int l=s.length();
    
    unordered_map<char,int>map;
     
    char max;
    int c=0;
     
    for(int i=0 ;i<l ; i++){
        map[s[i]]++;
         
        if(c < map[s[i]]){
            max = s[i];
            c = map[s[i]];
        }
    }
    
    vector<char> maxChars;
    for (const auto& pair : map) {
        if (pair.second == c) {
            maxChars.push_back(pair.first);
        }
    }
    
    cout << "Maximum occurring character(s): ";
    for (const auto& ch : maxChars) {
        cout << ch << " ";
    }
    return 0;

}