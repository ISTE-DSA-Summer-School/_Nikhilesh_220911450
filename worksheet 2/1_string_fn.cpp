
#include <iostream>
#include <string> 

using namespace std;


int main()
{
	string s;

	getline(cin, s);

	cout << "The initial string, input using getline is : ";
	cout << s << endl;

	s.push_back('.');

	cout << "The string after push_back a fullstop is : ";
	cout << s << endl;

	s.pop_back();

	cout << "The string after pop_back operation is : ";
	cout << s << endl;
	
	cout << "The length() of the string is";
    cout << s.length() << endl;
    
    s.resize(3);
    
    cout << "Resizing the string to 3 characters";
    cout << s;

	return 0;
}
