#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int n, k, tmp;
	cin>>n>>k;

	vector<int> window;
	for (int k_i=0; k_i<=k && k_i<n; k_i++) {
		cin>>tmp;
		window.push_back(tmp);
	}

	priority_queue<int, vector<int>, greater<int>> pq(window.begin(), window.end());
	for (int n_i=0; n_i<n; n_i++) {
		cout<<pq.top()<<" ";
		pq.pop();

		if (n_i < (n - k - 1)) {
			cin>>tmp;
			pq.push(tmp);
		}
	}
	cout<<endl;
	return 0;
}
