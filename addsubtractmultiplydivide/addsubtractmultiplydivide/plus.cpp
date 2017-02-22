#include<iostream>
using namespace std;
int main() {
	int input;
	double inputt;
	double inputtt;
	double inputttt;
	cout << "Input two numbers" << endl;
	cin >> inputt;
	cin >> inputtt;
	cout << "Do you want to add(1), subtract(2), multiply(3), or divide(4)" << endl;
	cin >> input;
	cout << endl;
	switch (input) {
	case 1: 
		cout << inputt + inputtt << endl;
		break;
	case 2:
		cout << inputt - inputtt << endl;
		break;
	case 3:
		cout << inputt*inputtt << endl;
		break;
	case 4:
		cout << inputt / inputtt << endl;
		break;
		
	}
}