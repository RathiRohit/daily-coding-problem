#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

int getSafePosition(int count, int step) {
	if(count == 1) {
		return 1;
	}

	if(step == 2) {
		if((count & 1) == 1) {
			return 2 * getSafePosition((count - 1) / 2, step) + 1;
		} else {
			return 2 * getSafePosition(count / 2, step) - 1;
		}
	}

	int currentKillPosition = (step % count) == 0 ? count : (step % count);
	int nextStartPosition = currentKillPosition == count ? 1 : currentKillPosition;
	int nextSafePosition = getSafePosition(count - 1, step);
	nextSafePosition = nextSafePosition + (nextStartPosition - 1);
	nextSafePosition = nextSafePosition > (count - 1) ? (nextSafePosition % count + 1) : nextSafePosition;

	if(nextSafePosition >= currentKillPosition) {
		return nextSafePosition + 1;
	}

	return nextSafePosition;
}

int main() {
	int n, k;
	cout<<"Enter count of people & step count:"<<endl;
	cin>>n>>k;

	cout<<"Last man standing: "<<getSafePosition(n, k)<<endl;
	return 0;
}
