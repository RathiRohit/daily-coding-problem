#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

vector<int> getSubsetForSumK(vector<int> arr, int sum, int index) {
	vector<int> resultSubset;

	if(index >= arr.size() || sum <= 0 || arr[index] > sum) {
		return resultSubset;
	}

	if(arr[index] == sum) {
		resultSubset.push_back(arr[index]);
		return resultSubset;
	}

	vector<int> subsetWithout = getSubsetForSumK(arr, sum, index + 1);

	if(!subsetWithout.empty()) {
		resultSubset.insert(resultSubset.end(), subsetWithout.begin(), subsetWithout.end());
		return resultSubset;
	}

	vector<int> subsetWith = getSubsetForSumK(arr, sum - arr[index], index + 1);
	if(!subsetWith.empty()) {
		resultSubset.push_back(arr[index]);
		resultSubset.insert(resultSubset.end(), subsetWith.begin(), subsetWith.end());
	}

	return resultSubset;
}

int main() {
	int n;
	cout<<"Enter number of integers in the array:"<<endl;
	cin>>n;

	vector<int> arr(n);
	cout<<"Enter "<<n<<" positive integers:"<<endl;
	for(int n_i=0; n_i<n; n_i++) {
		cin>>arr[n_i];
	}
	sort(arr.begin(), arr.end());

	int k;
	cout<<"Enter value of k:"<<endl;
	cin>>k;

	vector<int> subset = getSubsetForSumK(arr, k, 0);
	if(subset.size() == 0) {
		cout<<"Possible subset with sum "<<k<<": null"<<endl;
		return 0;
	}

	cout<<"Possible subset with sum "<<k<<":"<<endl;
	for(int i=0; i<subset.size(); i++) {
		cout<<subset[i]<<" ";
	}
	cout<<endl;
	return 0;
}
