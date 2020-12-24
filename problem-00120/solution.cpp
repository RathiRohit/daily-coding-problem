#include <iostream>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define ull unsigned long long

using namespace std;

class Cup {
    public:
        int label;
        Cup* next;
        Cup* prev;

        Cup(int label) {
            this->label = label;
            this->prev = NULL;
            this->next = NULL;
        }

        Cup(int label, Cup* prev, Cup* next) {
            this->label = label;
            this->prev = prev;
            this->next = next;
        }
};

Cup* getDestCup(unordered_map<int, Cup*>& cupMap, Cup* removed, int minLabel, int maxLabel, int dest) {
    unordered_set<int> removedCups;
    removedCups.insert(removed->label);
    removedCups.insert(removed->next->label);
    removedCups.insert(removed->next->next->label);

    if (dest < minLabel) {
        dest = maxLabel;
    }
    while (removedCups.count(dest) != 0) {
        dest--;
        if (dest < minLabel) {
            dest = maxLabel;
        }
    }

    return cupMap[dest];
}

int main() {
    string input;
    cin>>input;

    Cup* firstCup = new Cup(input[0] - '0');
    firstCup->prev = firstCup;
    firstCup->next = firstCup;

    Cup* start = firstCup;
    Cup* end = firstCup;
    unordered_map<int, Cup*> cupMap;
    cupMap[firstCup->label] = firstCup;
    int maxLabel = firstCup->label;
    int minLabel = firstCup->label;
    for (int i=1; i<input.size(); i++) {
        int label = input[i] - '0';
        Cup* nextCup = new Cup(label, end, start);
        start->prev = nextCup;
        end->next = nextCup;
        end = nextCup;

        cupMap[label] = nextCup;
        if (label > maxLabel) {
            maxLabel = label;
        }
        if (label < minLabel) {
            minLabel = label;
        }
    }

    Cup* currentCup = start;
    for (int move_i=0; move_i<100; move_i++) {
        Cup* removedCups = currentCup->next;
        Cup* nextCup = removedCups->next->next->next;

        nextCup->prev = currentCup;
        currentCup->next = nextCup;

        Cup* destCup = getDestCup(cupMap, removedCups, minLabel, maxLabel, currentCup->label - 1);
        removedCups->next->next->next = destCup->next;
        destCup->next->prev = removedCups->next->next;
        removedCups->prev = destCup;
        destCup->next = removedCups;

        currentCup = currentCup->next;
    }

    string ans = "";
    int firstLabel = 1;
    Cup* traveler = cupMap[1];
    do {
        traveler = traveler->next;
        if (firstLabel == traveler->label) {
            break;
        }
        ans += to_string(traveler->label);
    } while (true);

    cout<<ans<<endl;
	return 0;
}
