#include <iostream>

using namespace std;

void* operator new(size_t size) {
	cout << "Overloaded New operator with size : "<<size<<endl;
	void* ptr = malloc(size);
	return ptr;
}

void operator delete(void* ptr) {
	cout << "Overloaded delete" << endl;
	free(ptr);
}

class OppositeOperators {
private:
	int val;
public:
	OppositeOperators() {
		val = 0;
	}
	OppositeOperators(int data){
		val = data;
	}
	OppositeOperators operator +(OppositeOperators const& obj) {
		OppositeOperators result;
		result.val = val - obj.val;
		return result;
	}

	OppositeOperators operator -(OppositeOperators const& obj) {
		OppositeOperators result;
		result.val = val + obj.val;
		return result;
	}

	OppositeOperators operator /(OppositeOperators const& obj) {
		OppositeOperators result;
		result.val = val * obj.val;
		return result;
	}

	OppositeOperators operator *(OppositeOperators const& obj) {
		OppositeOperators result;
		try {
			if (obj.val != 0) {
				result.val = val / obj.val;
			}
			else {
				throw obj.val;
			}
		}
		catch (int temp) {
			cout << "Divide by 0 exception";
		}
		return result;
	}
	void printData() {
		cout << val << endl;
	}
};

int main() {
	OppositeOperators o1= OppositeOperators(2);
	OppositeOperators o2 = OppositeOperators(0);
	o1.printData();
	o2.printData();
	OppositeOperators o3 = o1 * o2;
	o3.printData();
	OppositeOperators* over1 = new OppositeOperators(1);
	delete(over1);
	getchar();
}