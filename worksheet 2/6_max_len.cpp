#include <iostream>
#include <string> 
#include <cstring>

using namespace std;

int main()
{
	string s,sub;
    int c = 0, m =0;
    
    cout << "Enter string" << endl;
	getline(cin, s);
    int l=s.length();
    
    for (int i = 0; i < l; i++) {
        if (s[i] != ' ')
            c++;
        else {
            m = max(m, c);
            c = 0;
        }
    }
    m = max(m, c);
    cout << "Length of largest word in sentence: " << m;
	return 0;
}