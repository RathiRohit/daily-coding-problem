#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

int getPapersWithCitations(vector<int> papers, int citations) {
    int left = 0;
    int right = papers.size() - 1;
    int maxPapersFound = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(papers[mid] >= citations) {
            if(mid + 1 > maxPapersFound) {
                maxPapersFound = mid + 1;
            }
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return maxPapersFound;
}

int main() {
    int n;
    cout<<"Enter number of papers:"<<endl;
    cin>>n;

    vector<int> papers(n);
    cout<<"Enter citation counts for "<<n<<" papers:"<<endl;
    for(int n_i=0; n_i<n; n_i++) {
        cin>>papers[n_i];
    }

    sort(papers.begin(), papers.end(), greater<int>());

    int hIndex = 0;
    for(int n_i=n; n_i>=0; n_i--) {
        int papersCount = getPapersWithCitations(papers, n_i);
        if(papersCount >= n_i) {
            hIndex = n_i;
            break;
        }
    }

    cout<<"h-index: "<<hIndex<<endl;
	return 0;
}
