#include <iostream>
#include <unordered_map>

#define ll long long
#define ull unsigned long long

using namespace std;

void processCode(
    char code, int value, int& northSouth, int& eastWest,
    int& direction, unordered_map<int, char>& angleMap
) {
    switch (code) {
        case 'E':
            eastWest += value;
            break;
        case 'W':
            eastWest -= value;
            break;
        case 'N':
            northSouth += value;
            break;
        case 'S':
            northSouth -= value;
            break;
        case 'L':
            direction -= value;
            direction %= 360;
            break;
        case 'R':
            direction += value;
            direction %= 360;
            break;
        case 'F':
            processCode(angleMap[direction], value, northSouth, eastWest, direction, angleMap);
            break;
    }
}

int main() {
    int n;
    cin>>n;

    int northSouth = 0;
    int eastWest = 0;
    int direction = 0;

    unordered_map<int, char> angleMap;
    angleMap[0] = 'E';
    angleMap[90] = 'S';
    angleMap[180] = 'W';
    angleMap[270] = 'N';
    angleMap[-90] = 'N';
    angleMap[-180] = 'W';
    angleMap[-270] = 'S';

    for (int n_i=0; n_i<n; n_i++) {
        string tmp;
        cin>>tmp;

        char code = tmp[0];
        int value = stoi(tmp.substr(1, tmp.size() - 1));

        processCode(code, value, northSouth, eastWest, direction, angleMap);
    }

    cout<<abs(northSouth) + abs(eastWest)<<endl;
	return 0;
}
