#include <iostream>
#include <climits>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int t;
    for (cin>>t; t>0; t--) {
        int n, salary;
        cin>>n;

        ll operations = 0;
        int minSalary = INT_MAX;
        for (int n_i=1; n_i<=n; n_i++) {
            cin>>salary;
            operations += salary - minSalary;

            if (salary < minSalary) {
                int diff = minSalary - salary;
                operations += diff * n_i;
                minSalary = salary;
            }
        }

        cout<<operations<<endl;
    }
	return 0;
}
