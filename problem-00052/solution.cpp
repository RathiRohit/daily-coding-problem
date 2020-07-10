#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

#define KAPREKAR_NUMBER 6174

using namespace std;

int countStepsToKaprekarNumber(int n, int stepCount) {
    if(n == KAPREKAR_NUMBER) {
        return stepCount;
    }

    if(n == 0) {
        throw "INVALID_INPUT_ERROR";
    }

    vector<int> digits(4);
    int tmp = n;

    for(int digits_i=3; digits_i>=0; digits_i--) {
        digits[digits_i] = tmp % 10;
        tmp /= 10;
    }

    int asc = 0;
    sort(digits.begin(), digits.end());
    for(int digits_i=0; digits_i<4; digits_i++) {
        asc *= 10;
        asc += digits[digits_i];
    }

    int dsc = 0;
    for(int digits_i=3; digits_i>=0; digits_i--) {
        dsc *= 10;
        dsc += digits[digits_i];
    }

    int newNum = dsc - asc;
    return countStepsToKaprekarNumber(newNum, stepCount + 1);
}

int main() {
    int n;
    cout<<"Enter any positive number with at least 2 distinct digits:"<<endl;
    cin>>n;

    try {
        int steps = countStepsToKaprekarNumber(n, 0);
        cout<<"Number of steps required to reach Kaprekar's number: ";
        cout<<steps<<endl;
    } catch(...) {
        cout<<"Something went wrong! But the code must work, so re-check your input once & try again.";
        cout<<endl;
    }
	return 0;
}
