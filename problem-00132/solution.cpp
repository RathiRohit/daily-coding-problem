#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

vector<string> stringSplit(string str, char deliminator) {
    vector<string> tokens;
    string token = "";
    for (char ch: str) {
        if (ch == deliminator) {
            tokens.push_back(token);
            token = "";
        } else {
            token += ch;
        }
    }
    tokens.push_back(token);
    return tokens;
}

int main() {
    int t;
    for (cin>>t; t; t--) {
        int commands;
        cin>>commands;

        vector<string> cwd;
        cwd.push_back("");

        for (int commands_i=0; commands_i<commands; commands_i++) {
            string command;
            cin>>command;

            if (command == "cd") {
                string path;
                cin>>path;

                if (path[0] == '/') {
                    cwd.clear();
                    cwd.push_back("");
                }

                vector<string> directories = stringSplit(path, '/');
                for (string directory: directories) {
                    if (directory == ".." && cwd.back() != "") {
                        cwd.pop_back();
                    } else if (directory != "") {
                        cwd.push_back(directory);
                    }
                }
            } else if (command == "pwd") {
                for (string directory: cwd) {
                    cout<<directory<<'/';
                }
                cout<<endl;
            }
        }
    }
	return 0;
}
