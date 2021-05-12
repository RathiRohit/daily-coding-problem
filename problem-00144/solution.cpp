class Solution {
    public:
        void duplicateZeros(vector<int>& arr) {
            int size = arr.size();
            int lastIndex = -1;
            bool halfLast = false;
            for (int arr_i=0; arr_i<size; arr_i++) {
                lastIndex++;
                if (arr[lastIndex] == 0) {
                    arr_i++;
                }
                if (arr_i >= size) {
                    halfLast = true;
                    break;
                }
            }

            int traveler = size - 1;
            if (halfLast) {
                arr[traveler] = arr[lastIndex];
                traveler--;
                lastIndex--;
            }
            for (int arr_j=lastIndex; arr_j>=0; arr_j--,traveler--) {
                arr[traveler] = arr[arr_j];
                if (arr[arr_j] == 0) {
                    traveler--;
                    arr[traveler] = arr[arr_j];
                }
            }
        }
};
