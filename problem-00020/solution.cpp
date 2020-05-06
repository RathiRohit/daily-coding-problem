#include <iostream>
#include <fstream>

#define ll long long
#define ull unsigned long long

using namespace std;

string read7(ifstream *fin) {
	char str[8];
	fin->read(str, 7);
	if(fin) {
		str[7] = '\0';
	} else {
		str[fin->gcount()] = '\0';
	}
	return string(str);
}

string readN(ifstream *fin, int n) {
	string result = "";
	while(n >= 7) {
		result = result + read7(fin);
		n -= 7;
	}
	if(n > 0) {
		result = result + read7(fin).substr(0, n);
	}
	return result;
}

int main() {
	string fileName;
	cout<<"Enter file name to read from:"<<endl;
	cin>>fileName;

	int n;
	cout<<"Enter number of characters to read from file:"<<endl;
	cin>>n;

	ifstream fin;
	fin.open(fileName);

	cout<<n<<"(or less than n) characters from file:"<<endl;
	cout<<readN(&fin, n)<<endl;

	return 0;
}
