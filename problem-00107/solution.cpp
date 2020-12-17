#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

bool invalid(int value, vector<int> limits) {
    if ((limits[0]<=value && value<=limits[1]) || (limits[2]<=value && value<=limits[3])) {
        return false;
    }
    return true;
}

int main() {
    int fieldCount;
    cin>>fieldCount;

    unordered_map<string, vector<int> > limitsMap;
    unordered_set<string> undecidedFields;
    for (int fieldCount_i=0; fieldCount_i<fieldCount; fieldCount_i++) {
        string field;
        cin>>field;

        vector<int> limits(4);
        cin>>limits[0]>>limits[1]>>limits[2]>>limits[3];

        limitsMap[field] = limits;
        undecidedFields.insert(field);
    }

    int numberCount = limitsMap.size();

    vector<vector<int> > tickets;
    vector<int> ownTicket(numberCount);
    for (int numberCount_i=0; numberCount_i<numberCount; numberCount_i++) {
        cin>>ownTicket[numberCount_i];
    }
    tickets.push_back(ownTicket);

    int ticketCount;
    cin>>ticketCount;

    for (int ticketCount_i=0; ticketCount_i<ticketCount; ticketCount_i++) {
        vector<int> ticket(numberCount);
        int validValues = 0;
        for (int numberCount_i=0; numberCount_i<numberCount; numberCount_i++) {
            cin>>ticket[numberCount_i];
            for (auto limitField: limitsMap) {
                if (!invalid(ticket[numberCount_i], limitField.second)) {
                    validValues++;
                    break;
                }
            }
        }
        if (validValues == numberCount) {
            tickets.push_back(ticket);
        }
    }

    ticketCount = tickets.size();
    unordered_map<string, int> fieldValueMap;

    while (undecidedFields.size() != 0) {
        for (int numberCount_i=0; numberCount_i<numberCount; numberCount_i++) {
            vector<string> validFieldForThisNumber;
            for (string field: undecidedFields) {
                bool thisIsTheField = true;
                for (int ticketCount_i=0; ticketCount_i<ticketCount; ticketCount_i++) {
                    if (invalid(tickets[ticketCount_i][numberCount_i], limitsMap[field])) {
                        thisIsTheField = false;
                        break;
                    }
                }
                if (thisIsTheField) {
                    validFieldForThisNumber.push_back(field);
                }
            }

            if (validFieldForThisNumber.size() == 1) {
                cout<<validFieldForThisNumber[0]<<" "<<numberCount_i<<endl;
                fieldValueMap[validFieldForThisNumber[0]] = numberCount_i;
                undecidedFields.erase(validFieldForThisNumber[0]);
                break;
            }
        }
    }

    ll ans = 1;
    for (auto fieldValue: fieldValueMap) {
        if (fieldValue.first.find("departure") != string::npos) {
            ans *= tickets[0][fieldValue.second];
        }
    }

    cout<<ans<<endl;
	return 0;
}
