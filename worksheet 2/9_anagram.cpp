#include <iostream>
#include <string> 
#include <cstring>

using namespace std;

string sortin(string str){
    char temp;
    int l = str.length();
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l - 1; j++){
            if (str[j] > str[j + 1]){ 
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
    return str;
}
int main()
{
	string s, s1;
	
    cout << "Enter string 1" << endl;
	getline(cin, s);
    int l=s.length();
    
    cout << "Enter string 2" << endl;
    getline(cin, s1);
    int l1=s1.length();
    
    s = sortin(s);
    s1 = sortin(s1);
    
    if(s == s1){
        cout << "Anagrams";
    }
    else
        cout << "Not anagrams";
    return 0;

}
