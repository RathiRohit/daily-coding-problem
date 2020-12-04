#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int n, m;
    cin>>n>>m;

    int currentPos = 0;
    int trees = 0;
    string row;
    cin>>row;
    for (int n_i=1; n_i<n; n_i++) {
        cin>>row;
        currentPos += 3;
        currentPos %= m;

        if (row[currentPos] == '#') {
            trees++;
        }
    }

    cout<<trees<<endl;
	return 0;
}
