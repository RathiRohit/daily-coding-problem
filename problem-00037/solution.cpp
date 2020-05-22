#include <iostream>
#include <string>

#define ll long long
#define ull unsigned long long

using namespace std;

int getClockAngle(string timeStr) {
	int hour = ((10 * (timeStr[0] - '0')) + (timeStr[1] - '0'));
	int min = ((10 * (timeStr[3] - '0')) + (timeStr[4] - '0'));

	if(hour >= 12) {
		hour -= 12;
	}

	int angleOfMinHand = min * 6;
	int angleOfHourHand = hour * 30;
	angleOfHourHand += min / 2;

	return abs(angleOfHourHand - angleOfMinHand);
}

int main() {
	string timeStr;
	cout<<"Enter time in hh:mm format:"<<endl;
	cin>>timeStr;

	cout<<"Angle between clock hands: "<<getClockAngle(timeStr)<<endl;
	cout<<endl<<"------------------------------------"<<endl<<endl;

	for(int hh=0; hh<24; hh++) {
		for(int mm=0; mm<60; mm++) {
			string timeStr = "";
			if(hh < 10) {
				timeStr.push_back('0');
			}
			timeStr.append(to_string(hh));
			timeStr.push_back(':');
			if(mm < 10) {
				timeStr.push_back('0');
			}
			timeStr.append(to_string(mm));

			if(getClockAngle(timeStr) == 0) {
				cout<<"Angle between clock hands is Zero @ "<<timeStr<<endl;
			}
		}
	}
	return 0;
}
