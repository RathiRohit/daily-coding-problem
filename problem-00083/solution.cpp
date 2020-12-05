#include <iostream>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    int n;
    cin>>n;

    int validPassports = 0;
    int fields = 0;
    int countryCodeNotFound = 1;
    for (int n_i=0; n_i<n;) {
        string field;
        string value;

        cin>>field;
        if (field == "---") {
            fields += countryCodeNotFound;
            validPassports += (fields == 8);
            n_i++;
            fields = 0;
            countryCodeNotFound = 1;
            continue;
        }
        cin>>value;

        try {
            if (field == "cid") {
                countryCodeNotFound = 0;
                fields++;
            } else if (field == "byr") {
                ll byr = stol(value);
                if (1920 <= byr && byr <= 2002) {
                    fields++;
                }
            } else if (field == "iyr") {
                ll iyr = stol(value);
                if (2010 <= iyr && iyr <= 2020) {
                    fields++;
                }
            } else if (field == "eyr") {
                ll eyr = stol(value);
                if (2020 <= eyr && eyr <= 2030) {
                    fields++;
                }
            } else if (field == "hgt") {
                string num = value.substr(0, value.size() - 2);
                ll hgt = stol(num);
                string unit = value.substr(value.size() - 2, 2);

                if (unit == "cm" && (150 <= hgt && hgt <= 193)) {
                    fields++;
                } else if (unit == "in" && (59 <= hgt && hgt <= 76)) {
                    fields++;
                }
            } else if (field == "hcl") {
                bool allValid = true;
                if (value.size() == 7 && value[0] == '#') {
                    for (int i=1; i<7; i++) {
                        if (
                            !(('0' <= value[i] && value[i] <= '9') || ('a' <= value[i] && value[i] <= 'f'))
                        ) {
                            allValid = false;
                        }
                    }
                    fields += allValid;
                }
            } else if (field == "ecl") {
                if (
                    value == "amb" || value == "blu" || value == "brn" || value == "gry" ||
                    value == "grn" || value == "hzl" || value == "oth"
                ) {
                    fields++;
                }
            } else if (field == "pid") {
                ll pid = stol(value);
                if (value.size() == 9 && pid < 1000000000) {
                    fields++;
                }
            }
        } catch (invalid_argument& ia) {}
    }

    cout<<validPassports<<endl;
	return 0;
}
