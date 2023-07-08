
#include <iostream>
#include <string> 
#include <cstring>

using namespace std;

int main()
{
	string s,sub;
    int c = 0;
    
    cout << "Enter string" << endl;
	getline(cin, s);
    int l=s.length();
    
    cout << "Enter substring" << endl;
    getline(cin, sub);
    int l1 = sub.length();
    
    
	size_t pos = 0;
    while ((pos = s.find(sub, pos)) != std::string::npos) {
        c++;
        pos += sub.length();
    }

	cout << "Occurrences: " << c;
	return 0;
}
