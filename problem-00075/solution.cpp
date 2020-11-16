class Solution {
    public:
        int getSum(int a, int b) {
            if (a >= 0) {
                while (a > 0) {
                    b++;
                    a--;
                }
            } else {
                while (a < 0) {
                    b--;
                    a++;
                }
            }
            
            return b;
        }
};
