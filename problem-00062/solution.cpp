#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

int getZeroIndex(int *arr, int n) {
    if(n == 1) {
        return 0;
    }

    int left = 0;
    int right = n-1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(arr[mid] > 0) {
            right = mid - 1;
            if(mid == 0 || arr[mid - 1] < 0) {
                return mid;
            }
        } else if(arr[mid] < 0) {
            left = mid + 1;
            if(mid == n-1 || arr[mid + 1] > 0) {
                return mid + 1;
            }
        } else {
            if(mid != 0 && arr[mid - 1] == 0) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
    }
    return 0;
}

int main() {
    int n;
    cout<<"Enter number of elements in the array:"<<endl;
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<" sorted integers:"<<endl;
    for(int n_i=0; n_i<n; n_i++) {
        cin>>arr[n_i];
    }

    int right = getZeroIndex(arr, n);
    int left = right - 1;
    cout<<"Sorted output of squared elements:"<<endl;
    while(left >= 0 && right < n) {
        if(abs(arr[left]) <= arr[right]) {
            cout<<arr[left]*arr[left]<<" ";
            left--;
        } else {
            cout<<arr[right]*arr[right]<<" ";
            right++;
        }
    }
    while(left >= 0) {
        cout<<arr[left]*arr[left]<<" ";
        left--;
    }
    while(right < n) {
        cout<<arr[right]*arr[right]<<" ";
        right++;
    }
    cout<<endl;
	return 0;
}
