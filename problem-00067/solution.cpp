class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            vector<string> ans;
            if (digits.size() == 0) {
                return ans;
            }
            
            vector<string> letters = getLetters(digits[0]);
            if (digits.size() == 1) {
                return letters;
            }
            
            vector<string> nextLetters = letterCombinations(digits.substr(1, digits.size() - 1));
            for (string str: letters) {
                for (string nextStr: nextLetters) {
                    ans.push_back(str + nextStr);
                }
            }
            return ans;
        }
    
        vector<string> getLetters(char digit) {
            switch(digit) {
                case '2':
                    return vector<string>{"a", "b", "c"};
                case '3':
                    return vector<string>{"d", "e", "f"};
                case '4':
                    return vector<string>{"g", "h", "i"};
                case '5':
                    return vector<string>{"j", "k", "l"};
                case '6':
                    return vector<string>{"m", "n", "o"};
                case '7':
                    return vector<string>{"p", "q", "r", "s"};
                case '8':
                    return vector<string>{"t", "u", "v"};
                case '9':
                    return vector<string>{"w", "x", "y", "z"};
                default:
                    return vector<string>();
            }
            return vector<string>();
        }
};
