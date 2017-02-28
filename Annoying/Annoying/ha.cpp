#include<iostream>
using namespace std;
#include<windows.h>
void annoying();
int main() {
	annoying();
	
	}
void annoying() {
	MessageBox(NULL, "You're too slow!", "Soncis the name. Speed's my game!", NULL);
	Beep(200, 1000);
	Beep(300, 1000);
	Beep(400, 1000);
	Beep(10000, 10000);
	system("color 4A");
}