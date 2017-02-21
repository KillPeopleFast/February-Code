#include<iostream>
using namespace std;
int main() {
	int type;

	cout << "WHat type o cookie do you want.??" << endl;
	cout << " Oatmeal, peanut butter, or CHOCOLOTO" << endl;
	cout << "UNO    DOS    TRES?" << endl;
	cin>> type;
	switch (type) {

	case 1:
		cout << "Oatmeal COOKIES FO Ye" << endl;

		break;
	case 2:
		cout << "Peanut Butter COOKEIS FOr u" << endl;
		break;
	case 3:
		cout << "CHOCOLOTO Cokies 4 U" << endl;
		break;

	}
}