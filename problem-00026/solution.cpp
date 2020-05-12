#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#define ll long long
#define ull unsigned long long

using namespace std;

void printTopThree(vector<pair<int, string> > topThree) {
	cout<<"Top 3 candidates right now are:"<<endl;
	for(int i=0; i<3; i++) {
		if(topThree[i].first <= 0) {
			break;
		}
		cout<<topThree[i].second<<"("<<topThree[i].first<<")    ";
	}
	cout<<endl;
}

void updateTopThree(vector<pair<int, string> >& topThree, pair<int, string> current) {
	bool alreadyPresent = false;
	for(int i=0; i<3; i++) {
		if(topThree[i].second == current.second) {
			topThree[i].first = current.first;
			alreadyPresent = true;
			break;
		}
	}

	if(!alreadyPresent) {
		topThree.push_back(current);
	}

	sort(topThree.begin(), topThree.end(), greater<pair<int, string> >());
	if(topThree.size() == 4) {
		topThree.pop_back();
	}
}

int main() {
	string fileName;
	cout<<"Enter file name for vote log:"<<endl;
	cin>>fileName;

	ifstream fin;
	fin.open(fileName);

	char str[1001];
	map<string, int> voteCount;
	map<string, bool> hasVoted;

	vector<pair<int, string> > topThree;
	topThree.push_back(make_pair(0, string("")));
	topThree.push_back(make_pair(0, string("")));
	topThree.push_back(make_pair(0, string("")));

	while(fin) {
		fin.getline(str, 1000);
		if(fin.eof()) {
			break;
		}

		string record(str);
		int midPos = record.find(',');
		string voterID = record.substr(1, midPos - 1);
		string candidateID = record.substr(midPos + 2, record.length() - (midPos + 2) - 1);

		cout<<"--------------------------------------------------------------------------"<<endl;
		if (hasVoted.count(voterID) == 1) {
			cout<<"FRAUD: "<<voterID<<" is fraud, and this new vote will not be counted!"<<endl;
			continue;
		}
		hasVoted[voterID] = true;
		voteCount[candidateID]++;

		updateTopThree(topThree, make_pair(voteCount[candidateID], candidateID));
		printTopThree(topThree);
	}
	return 0;
}
