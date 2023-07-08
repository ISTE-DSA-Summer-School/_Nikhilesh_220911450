#include <iostream>
#include <string> 

using namespace std;


int main()
{
	string s;

	cin >> s;

// 	cout << s << endl;
    
    string s1 = s;
    
    int c =0;
    for(int i=0; s[i];i++){
        c++;
    }
    cout << c << endl;
    for(int j=0; s[j]; j++){
        s1[c-1-j]=s[j];
    }
	
	cout << s << endl << s1;
	
	return 0;
}
