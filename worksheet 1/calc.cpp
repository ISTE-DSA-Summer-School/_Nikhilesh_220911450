#include <iostream>

using namespace std;

float calc(float a,float b,char op){
    if(op == '+')
        return a + b;
    if(op == '-')
        return a - b;
    if(op == '*')
        return a*b;
    if(op == '/')
        return a/b;
}


int main()
{
    float a,b;
    char op;
    cout << "Enter two numbers";
    cin >> a >> b;
    cout << "Enter operand";
    cin >> op;
    cout << calc(a,b,op);

    return 0;
}
