#include <iostream>
#include <forward_list>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    char charMap[26] = {'0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'};
    forward_list<char> word;

    string str;
    forward_list<char>::iterator it;
    cout<<"Enter word:"<<endl;
    cin>>str;
    it = word.insert_after(word.before_begin(), str[0]);
    for(int str_i=1; str_i<str.size(); str_i++) {
        it = word.insert_after(it, str[str_i]);
    }

    it = word.begin();
    char tmp = *it;
    if(65 <= tmp && tmp <= 90) {
        tmp += 32;
    }
    *it = charMap[tmp - 'a'];
    forward_list<char>::iterator prev = word.begin();
    for(++it; it!=word.end();) {
        *it = charMap[*it - 'a'];

        if(*prev == *it) {
            it = word.erase_after(prev);
        } else {
            prev = it;
            it++;
        }
    }

    *(word.begin()) = str[0];
    if(97 <= str[0] && str[0] <= 122) {
        *(word.begin()) -= 32;
    }
    word.remove('0');

    int count = 0;
    cout<<"Word after applying Soundex algorithm:"<<endl;
    it = word.begin();
    while(it != word.end() && count < 4) {
        cout<<*it;
        count++;
        it++;
    }
    while(count < 4) {
        cout<<'0';
        count++;
    }
    cout<<endl;
	return 0;
}
