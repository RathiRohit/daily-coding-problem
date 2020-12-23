#include <iostream>
#include <queue>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int p1Count;
    cin>>p1Count;
    queue<int> p1Cards;
    for (int p1_i=0; p1_i<p1Count; p1_i++) {
        int tmp; cin>>tmp;
        p1Cards.push(tmp);
    }

    int p2Count;
    cin>>p2Count;
    queue<int> p2Cards;
    for (int p2_i=0; p2_i<p2Count; p2_i++) {
        int tmp; cin>>tmp;
        p2Cards.push(tmp);
    }

    while (!p1Cards.empty() && !p2Cards.empty()) {
        int p1Card = p1Cards.front();
        p1Cards.pop();
        int p2Card = p2Cards.front();
        p2Cards.pop();

        if (p1Card > p2Card) {
            p1Cards.push(p1Card);
            p1Cards.push(p2Card);
        } else {
            p2Cards.push(p2Card);
            p2Cards.push(p1Card);
        }
    }

    queue<int>* winner;
    if (!p1Cards.empty()) {
        winner = &p1Cards;
    } else {
        winner = &p2Cards;
    }

    int ans = 0;
    int multiplier = winner->size();
    for (;multiplier>0; multiplier--) {
        ans += multiplier * winner->front();
        winner->pop();
    }

    cout<<ans<<endl;
	return 0;
}
