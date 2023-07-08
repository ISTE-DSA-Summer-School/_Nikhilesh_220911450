#include <iostream>
#include <string> 

using namespace std;

string reverse(string s){
    string s1 =s;
    int l=s.length();
    for(int i=0; s[i]; i++){
        s1[l-1-i]=s[i];
    }
    return s1;
}

int main()
{
	string s;

	cin >> s;
    int l=s.length();
    int mid = l/2;
    char middle;
    string fh,sh,s1;
    
	if(l%2==0){
	    fh = s.substr(0,mid);
	    sh = s.substr(mid+1,mid);
	    fh = reverse(fh);
	    sh = reverse(sh);
	    s1= fh+sh;
	}
	else{
	    fh = s.substr(0,mid);
	    middle = s[mid];
	    sh = s.substr(mid+1,mid);
	    fh = reverse(fh);
	    sh = reverse(sh);
	    s1=fh+middle+sh;
	}
	
	
	cout << s1;
	
	return 0;
}