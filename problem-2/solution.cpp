#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>

#define ll long long
#define ull unsigned long long

using namespace std;

struct Data {
	char type;
	int value;
	char symbol;

	Data(int value) {
		this->type = 'i';
		this->value = value;
	}

	Data(char symbol) {
		this->type = 's';
		this->symbol = symbol;
	}
};

int main() {
	int inputLength;
	cout<<"Enter input length:"<<endl;
	cin>>inputLength;

	stack<Data> inputStack;
	for(int inputLength_i=0; inputLength_i<inputLength; inputLength_i++) {
		char type;
		cout<<"Enter next type (i/s):"<<endl;
		cin>>type;

		if(type == 'i') {
			int value;
			cout<<"Enter integer:"<<endl;
			cin>>value;

			inputStack.push(Data(value));
		} else {
			char symbol;
			cout<<"Enter symbol:"<<endl;
			cin>>symbol;

			if(inputStack.size() < 2) {
				cout<<"Wrong input! No enough data to perform operation."<<endl;
				return 1;
			}

			Data lastValue = inputStack.top();
			inputStack.pop();
			Data secondLastValue = inputStack.top();
			inputStack.pop();

			if(lastValue.type != 'i' || secondLastValue.type != 'i') {
				cout<<"Wrong input! Previous values are not numbers."<<endl;
				return 1;
			}

			Data resultValue(0);
			switch(symbol) {
				case '+':
					resultValue.value = secondLastValue.value + lastValue.value;
					break;
				case '-':
					resultValue.value = secondLastValue.value - lastValue.value;
					break;
				case '*':
					resultValue.value = secondLastValue.value * lastValue.value;
					break;
				case '/':
					resultValue.value = secondLastValue.value / lastValue.value;
					break;
				default:
					cout<<"Wrong input! Operator not supported."<<endl;
					return 1;
			}

			inputStack.push(resultValue);
		}
	}

	if(inputStack.size() != 1 || inputStack.top().type != 'i') {
		cout<<"Wrong input! Invalid result."<<endl;
		return 1;
	}

	cout<<inputStack.top().value<<endl;
	inputStack.pop();

	return 0;
}
