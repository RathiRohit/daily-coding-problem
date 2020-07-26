#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

int divisionWithoutDivision(int a, int b) {
    int quotient = 0;
    while(a >= b) {
        a -= b;
        quotient++;
    }
    return quotient;
}

int main() {
    int a, b;
    cout<<"Enter two positive integers:"<<endl;
    cin>>a>>b;

    if(a < 1 || b < 1) {
        cout<<"When I said 'positive integers', I meant it."<<endl;
        return 1;
    }

    cout<<a<<"÷"<<b<<" = "<<divisionWithoutDivision(a, b)<<endl;
	return 0;
}
