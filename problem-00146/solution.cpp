class Solution {
	public:
		string convert(string s, int numRows) {
            if (numRows == 1) {
                return s;
            }
            
			string result = "";
			int firstIncrement = ((numRows - 2)*2 + 1) + 1;
			int secondIncrement = 0;
			for (int s_i=0; firstIncrement>=0; s_i++) {
				bool first = true;
				for (int s_j=s_i; s_j<s.size();) {
					if (first) {
						if (firstIncrement != 0) {
							result += s[s_j];
						}
						s_j += firstIncrement;
					} else {
						if (secondIncrement != 0) {
							result += s[s_j];
						}
						s_j += secondIncrement;
					}
					first = !first;
				}
				firstIncrement -= 2;
				secondIncrement += 2;
			}
            return result;
		}
};
