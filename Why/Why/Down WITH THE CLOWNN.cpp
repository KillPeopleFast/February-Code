//Using a while loop, write a program that continuously asks a user if they want a cookie.If they say 'y',
//the program prints out a cookie, and continuously does this until the user types something else.

#include<iostream>
using namespace std;
int main() {
	
	char input = 'a';//dummy value
	while (input != 'q') {
		cout << "Would you like a cookie?" << endl;
		cin >> input;
		if (input == 'y')
			cout << "*COOKIE*" << endl;
		else if (input == 'n')
			cout << "no cookies :(" << endl;

	}
}