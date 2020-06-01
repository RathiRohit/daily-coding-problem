#include <iostream>
#include <chrono>
#include <random>
#include <iomanip>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {

	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	uniform_real_distribution<double> distribution(0.0, 1.0);

	double totalCount = 0;
	double insideCount = 0;
	ull limit = 1e+9;

	cout<<"Calculating value of π with sample size of: "<<limit<<endl;
	for(ull i=0; i<limit; i++) {
		double randomX = distribution(generator);
		double randomY = distribution(generator);

		if((randomX*randomX + randomY*randomY) <= 1) {
			insideCount += 1;
		}
		totalCount += 1;
	}

	double estimatedPi = (insideCount / totalCount) * 4;
	cout<<"Estimated value of π to 3 decimal places: ";
	cout<<fixed<<setprecision(3)<<estimatedPi<<endl;
	return 0;
}
