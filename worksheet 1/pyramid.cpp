#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter number of rows";
    cin >> n;
    int i,j,k;
    for( i = 1; i <= n; i++)
    {
        for( j = 0; j < n - i; j++)
            cout<<" ";
           
        for(k = 1; k <= i; k++)
          cout<<"* ";
        cout<<endl;
    }

    return 0;
}