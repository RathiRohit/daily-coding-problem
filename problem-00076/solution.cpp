#include <iostream>
#include <unordered_set>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int count;
    cin>>count;

    unordered_set<int> expenses;

    for(int count_i=0; count_i<count; count_i++) {
        int tmp;
        cin>>tmp;

        if (expenses.count(2020 - tmp) == 1) {
            cout<<tmp*(2020 - tmp)<<endl;
            return 0;
        }

        expenses.insert(tmp);
    }

	return 1;
}
