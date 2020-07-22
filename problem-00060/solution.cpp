#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

void printXchars(char ch, int x, bool enterNewLine) {
    for(int i=0; i<x; i++) {
        cout<<ch;
    }
    if(enterNewLine) {
        cout<<endl;
    }
}

int main() {
    vector<int> slantedDominoes;
    int pos = 1;
    cout<<"Enter dominoes sequence string:"<<endl;
    cin>>noskipws;
    while(true) {
        char tmp;
        cin>>tmp;
        if(tmp == 'L') {
            slantedDominoes.push_back(0 - pos);
        } else if(tmp == 'R') {
            slantedDominoes.push_back(pos);
        } else if(tmp != '.') {
            break;
        }
        pos++;
    }
    cin>>skipws;
    cout<<"When dominoes stop behaving like dominoes:"<<endl;

    if(slantedDominoes.size() == 0) {
        printXchars('.', pos - 1, true);
        return 0;
    }

    if(slantedDominoes[0] < 0) {
        printXchars('L', abs(slantedDominoes[0]), false);
    } else {
        printXchars('.', slantedDominoes[0] - 1, false);
        cout<<'R';
    }
    for(int pos_i=1; pos_i<slantedDominoes.size(); pos_i++) {
        int currentPos = abs(slantedDominoes[pos_i - 1]);
        int nextPos = abs(slantedDominoes[pos_i]);

        if(slantedDominoes[pos_i - 1] < 0 && slantedDominoes[pos_i] < 0) {
            printXchars('L', nextPos - currentPos, false);
        } else if(slantedDominoes[pos_i - 1] > 0 && slantedDominoes[pos_i] > 0) {
            printXchars('R', nextPos - currentPos, false);
        } else if(slantedDominoes[pos_i - 1] < 0 && slantedDominoes[pos_i] > 0) {
            printXchars('.', nextPos - currentPos - 1, false);
            cout<<'R';
        } else if(slantedDominoes[pos_i - 1] > 0 && slantedDominoes[pos_i] < 0) {
            int dominoesInBetween = nextPos - currentPos - 1;
            int dominoesInHalf = dominoesInBetween / 2;
            printXchars('R', dominoesInHalf, false);
            if(dominoesInBetween % 2 == 1) {
                cout<<'.';
            }
            printXchars('L', dominoesInHalf, false);
            cout<<'L';
        }
    }
    int lastSlantedDominoesIndex = slantedDominoes.size() - 1;
    if(slantedDominoes[lastSlantedDominoesIndex] > 0) {
        printXchars('R', pos - abs(slantedDominoes[lastSlantedDominoesIndex]) - 1, false);
    } else {
        printXchars('.', pos - abs(slantedDominoes[lastSlantedDominoesIndex]) - 1, false);
    }

    cout<<endl;
	return 0;
}
