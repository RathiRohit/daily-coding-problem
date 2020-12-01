#include <iostream>
#include <set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int count;
    cin>>count;

    set<int> expensesSet;
    vector<int> expenses;
    for(int count_i=0; count_i<count; count_i++) {
        int tmp;
        cin>>tmp;

        if (expensesSet.count(tmp) == 0) {
            expensesSet.insert(tmp);
            expenses.push_back(tmp);
        }
    }

    for (int expenses_i = 0; expenses_i < (expenses.size() - 2); expenses_i++) {
        for (int expenses_j = expenses_i + 1; expenses_j < (expenses.size() - 1); expenses_j++) {
            int a = expenses[expenses_i];
            int b = expenses[expenses_j];
            int c = 2020 - a - b;
            if (expensesSet.count(c) == 1) {
                cout<<a*b*c<<endl;
                return 0;
            }
        }
    }

	return 1;
}
