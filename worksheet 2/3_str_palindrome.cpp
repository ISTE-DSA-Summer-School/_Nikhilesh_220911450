#include <iostream>
#include <string> 

using namespace std;


int main()
{
	string s;

	cin >> s;

// 	cout << s << endl;

    int l = s.length();
    bool flag = true;

    for(int i=0; i<l/2; i++){
        if(s[i]!=s[l-1-i]){
            flag = false;
            break;
        }
    }
	
	if(flag == true)
	    cout << "String is a palindrome";
	else
	    cout << "String is not a palindrome";
	
	return 0;
}