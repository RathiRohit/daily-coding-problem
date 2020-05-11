#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

int getXorY(int x, int y, int b) {
	return ((x * b) + (y * (1 - b)));
}

int main() {
	int x, y;
	cout<<"Enter values for x & y:"<<endl;
	cin>>x>>y;

	int b;
	cout<<"Enter value for b (1 or 0):"<<endl;
	cin>>b;

	cout<<"Result: "<<getXorY(x, y, b)<<endl;
	return 0;
}
