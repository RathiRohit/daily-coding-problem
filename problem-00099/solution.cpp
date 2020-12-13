#include <iostream>
#include <unordered_map>

#define ll long long
#define ull unsigned long long

using namespace std;

int northSouth = 1;
int eastWest = 10;
int shipEastWest = 0;
int shipNorthSouth = 0;

void processCode(char code, int value, int& northSouth, int& eastWest) {
    int tmp1 = eastWest;
    int tmp2 = northSouth;
    int tmp3 = northSouth;
    int tmp4 = eastWest;

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
            value %= 360;
            switch (value) {
                case 0:
                    break;
                case 90:
                    eastWest = -1 * northSouth;
                    northSouth = tmp1;
                    break;
                case 180:
                    eastWest = -1 * eastWest;
                    northSouth = -1 * northSouth;
                    break;
                case 270:
                    northSouth = -1 * eastWest;
                    eastWest = tmp2;
                    break;
            }
            break;
        case 'R':
            value %= 360;
            switch (value) {
                case 0:
                    break;
                case 90:
                    northSouth = -1 * eastWest;
                    eastWest = tmp3;
                    break;
                case 180:
                    eastWest = -1 * eastWest;
                    northSouth = -1 * northSouth;
                    break;
                case 270:
                    eastWest = -1 * northSouth;
                    northSouth = tmp4;
                    break;
            }
            break;
        case 'F':
            shipEastWest += eastWest * value;
            shipNorthSouth += northSouth * value;
            break;
    }
}

int main() {
    int n;
    cin>>n;

    for (int n_i=0; n_i<n; n_i++) {
        string tmp;
        cin>>tmp;

        char code = tmp[0];
        int value = stoi(tmp.substr(1, tmp.size() - 1));

        processCode(code, value, northSouth, eastWest);
    }

    cout<<abs(shipNorthSouth) + abs(shipEastWest)<<endl;
	return 0;
}

