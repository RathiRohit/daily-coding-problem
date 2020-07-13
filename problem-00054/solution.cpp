#include <iostream>
#include <map>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int n;
    cout<<"Enter number of elements in array:"<<endl;
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<" positive integers:"<<endl;
    for(int arr_i=0; arr_i<n; arr_i++) {
        cin>>arr[arr_i];
    }

    map<int, pair<int, int> > required;
    for(int arr_i=0; arr_i<n-1; arr_i++) {
        int arr_i2 = arr[arr_i] * arr[arr_i];
        if(required.count(arr_i2) != 0) {
            cout<<"Pythagorean triplet found:"<<endl;
            cout<<"("<<required[arr_i2].first;
            cout<<", "<<required[arr_i2].second;
            cout<<", "<<arr[arr_i]<<")"<<endl;
            return 0;
        }

        for(int arr_j=arr_i+1; arr_j<n; arr_j++) {
            int arr_j2 = arr[arr_j] * arr[arr_j];
            if(required.count(arr_j2) != 0) {
                cout<<"Pythagorean triplet found:"<<endl;
                cout<<"("<<required[arr_j2].first;
                cout<<", "<<required[arr_j2].second;
                cout<<", "<<arr[arr_j]<<")"<<endl;
                return 0;
            }

            int requiredSquare = arr_i2 + arr_j2;
            required[requiredSquare] = make_pair(arr[arr_i], arr[arr_j]);
        }
    }

    cout<<"Pythagoras would be very sad."<<endl;
    cout<<"No triplets found in the array."<<endl;
	return 0;
}
