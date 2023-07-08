#include <iostream>
#include <string> 
#include <cstring>

using namespace std;

int main()
{
	string s;
    cout << "Enter string" << endl;
	getline(cin, s);
    int l=s.length();
    
    for (int i = 0; i < l; i++) {
        char c = s[i];
        if (c >= 97 && c <= 122){
            s[i] -= 32;
        }
    }
    
    cout << "All capitals: " << s;
	return 0;
}