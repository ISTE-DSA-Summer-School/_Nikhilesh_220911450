#include <iostream>
#include <string> 
#include <cstring>

using namespace std;

int main()
{
	string s;
	char c;
	int index = -1;
    cout << "Enter string" << endl;
	getline(cin, s);
    int l=s.length();
    
    for (int i = 0; i < s.length(); i++) {
 
        if (s.find(s[i], s.find(s[i]) + 1) == string::npos) {
            cout << "First non-repeating character is " << s[i];
            return 0;
        }
    }
    cout << "All characters are repeating";
    return 0;

}