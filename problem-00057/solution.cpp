#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int n;
    cout<<"Enter value of N:"<<endl;
    cin>>n;

    char arr[n+1];
    cout<<"Enter clue array:"<<endl;
    for(int arr_i=0; arr_i<=n; arr_i++) {
        cin>>arr[arr_i];
    }

    int result[n+1];
    int lowest = 0, highest = n;
    for(int arr_i=n; arr_i>=0; arr_i--) {
        if(arr[arr_i] == '+') {
            result[arr_i] = highest;
            highest--;
        } else {
            result[arr_i] = lowest;
            lowest++;
        }
    }

    cout<<"Reconstructed array:"<<endl;
    for(int arr_i=0; arr_i<=n; arr_i++) {
        cout<<result[arr_i]<<" ";
    }
    cout<<endl;
	return 0;
}
