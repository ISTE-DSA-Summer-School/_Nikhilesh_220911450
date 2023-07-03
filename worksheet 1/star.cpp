#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter number of rows";
    cin >> n;
    int i,j,k;
    for(i =0; i<n; i++){
        for(j=0;j <=i;j++){
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
