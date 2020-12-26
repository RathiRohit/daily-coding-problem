#include <iostream>

#define ll long long
#define ull unsigned long long

#define MOD 20201227
#define LOOP_LIMIT 100000000
#define SUB_KEY 7

using namespace std;

int main() {
    ull pubKey = 1;
    ull cardLoopSize = 0, doorLoopSize = 0;
    ull cardPubKey, doorPubKey;
    cin>>cardPubKey>>doorPubKey;

    for (ull loopSize=1; loopSize<LOOP_LIMIT; loopSize++) {
        pubKey *= SUB_KEY;
        pubKey %= MOD;

        if (pubKey == cardPubKey) {
            cardLoopSize = loopSize;
        }
        if (pubKey == doorPubKey) {
            doorLoopSize = loopSize;
        }
        if (cardLoopSize != 0 && doorLoopSize != 0) {
            break;
        }
    }
    cout<<"Card's loop size: "<<cardLoopSize<<endl;
    cout<<"Door's loop size: "<<doorLoopSize<<endl;

    ull encKey = 1;
    for (int i=0; i<doorLoopSize; i++) {
        encKey *= cardPubKey;
        encKey %= MOD;
    }
    cout<<"Encryption key: "<<encKey<<endl;
	return 0;
}
