#include <iostream>
#include <unordered_map>

#define ll long long
#define ull unsigned long long

using namespace std;

template <typename T>
class SparseArray {
	int size;
	unordered_map<int, T> data;

	public:
		SparseArray() {
			this->size = -1;
		}

		void init(T *arr, int inputSize) {
			for(int arr_i=0; arr_i<inputSize; arr_i++) {
				if(arr[arr_i] != 0) {
					data[arr_i] = arr[arr_i];
				}
			}
			size = inputSize;
		}

		void set(int index, T val) {
			validate(index);

			data[index] = val;
			if(val == 0) {
				data.erase(index);
			}
		}

		T get(int index) {
			validate(index);

			if(data.count(index) == 0) {
				return 0;
			}
			return data[index];
		}

	private:
		void validate(int index) {
			if(size == -1) {
				throw "Tried to use SparseArray before initializing.";
			}
			if(index >= size || index < 0) {
				throw "Index out of bound.";
			}
		}
};

int main() {
	try {
		int arr[] = {1, 2, 3, 4, 5, 6};
		int size = 6;

		SparseArray<int> sArray;

		sArray.init(arr, size);
		cout<<"arr[0] = "<<sArray.get(0)<<endl;
		cout<<"arr[1] = "<<sArray.get(1)<<endl;
		cout<<"arr[2] = "<<sArray.get(2)<<endl;
		cout<<"arr[3] = "<<sArray.get(3)<<endl;
		cout<<"arr[4] = "<<sArray.get(4)<<endl;
		cout<<"arr[5] = "<<sArray.get(5)<<endl;

		sArray.set(0, 5);
		sArray.set(1, 3);
		sArray.set(2, 0);
		sArray.set(4, 0);

		cout<<"arr[0] = "<<sArray.get(0)<<endl;
		cout<<"arr[1] = "<<sArray.get(1)<<endl;
		cout<<"arr[2] = "<<sArray.get(2)<<endl;
		cout<<"arr[3] = "<<sArray.get(3)<<endl;
		cout<<"arr[4] = "<<sArray.get(4)<<endl;
		cout<<"arr[5] = "<<sArray.get(5)<<endl;
	} catch(char const *e) {
		cout<<endl<<"ERROR: "<<e<<endl;
		return 1;
	}
	return 0;
}
