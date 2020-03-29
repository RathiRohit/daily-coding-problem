#include <iostream>
#include <map>
#include <stdlib.h>
#include <time.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int n;
	cout<<"Enter count of numbers:"<<endl;
	cin>>n;

	double probabilities[n];
	cout<<"Enter probabilities of "<<n<<" numbers:"<<endl;
	for(int n_i=0; n_i<n; n_i++) {
		cin>>probabilities[n_i];
	}

	srand(time(NULL));

	int run = 1;
	while(true) {
		cout<<"Enter 1 to run the function, 0 to exit:"<<endl;
    	cin>>run;

    	if(run == 0) {
    		break;
    	}

    	double randomNumber = ((double) rand() / (RAND_MAX));
    	double sum = 0;
    	for(int n_i=0; n_i<n; n_i++) {
    		sum += probabilities[n_i];
    		if(randomNumber <= sum) {
    			cout<<"Number: "<<n_i + 1<<endl;
    			break;
    		}
    	}
	}
	return 0;
}
