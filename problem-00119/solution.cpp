#include <iostream>
#include <queue>
#include <unordered_set>

#define ll long long
#define ull unsigned long long

using namespace std;

string getRoundString(queue<int>& p1Cards, queue<int>& p2Cards) {
    string p1 = "";
    int p1Count = p1Cards.size();
    for (int i=0; i<p1Count; i++) {
        int tmp = p1Cards.front();
        p1 = p1 + "-" + to_string(tmp);
        p1Cards.pop();
        p1Cards.push(tmp);
    }
    string p2 = "";
    int p2Count = p2Cards.size();
    for (int i=0; i<p2Count; i++) {
        int tmp = p2Cards.front();
        p2 = p2 + "-" + to_string(tmp);
        p2Cards.pop();
        p2Cards.push(tmp);
    }

    return p1 + " & " + p2;
}

int playRecursive(queue<int>& p1Cards, queue<int>& p2Cards) {
    unordered_set<string> previousRounds;

    while (!p1Cards.empty() && !p2Cards.empty()) {
        string thisRound = getRoundString(p1Cards, p2Cards);
        if (previousRounds.count(thisRound) != 0) {
            return 1;
        }
        previousRounds.insert(thisRound);

        int p1Card = p1Cards.front();
        p1Cards.pop();
        int p2Card = p2Cards.front();
        p2Cards.pop();

        if (p1Cards.size() >= p1Card && p2Cards.size() >= p2Card) {
            queue<int> tmp1Queue(p1Cards);
            queue<int> tmp2Queue(p2Cards);
            queue<int> p1CloneCards;
            queue<int> p2CloneCards;
            for (int i=0; i<p1Card; i++) {
                int tmp = tmp1Queue.front();
                tmp1Queue.pop();
                p1CloneCards.push(tmp);
            }
            for (int i=0; i<p2Card; i++) {
                int tmp = tmp2Queue.front();
                tmp2Queue.pop();
                p2CloneCards.push(tmp);
            }

            if (playRecursive(p1CloneCards, p2CloneCards) == 1) {
                p1Cards.push(p1Card);
                p1Cards.push(p2Card);
            } else {
                p2Cards.push(p2Card);
                p2Cards.push(p1Card);
            }
        } else {
            if (p1Card > p2Card) {
                p1Cards.push(p1Card);
                p1Cards.push(p2Card);
            } else {
                p2Cards.push(p2Card);
                p2Cards.push(p1Card);
            }
        }
    }

    if (!p1Cards.empty()) {
        return 1;
    }
    return 2;
}

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

    queue<int>* winner;
    if (playRecursive(p1Cards, p2Cards) == 1) {
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
