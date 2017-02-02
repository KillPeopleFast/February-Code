#include<iostream>
using namespace std;

int main() {
	int song;

	cout << "1)Rick Astley Never Gonna Give You Up" << endl;
	cout << "2)Bring Me The Horizon Drown" << endl;
	cout << "3)Childish Gambino Sweatpants" << endl;
	cout << "4)Chance the Rapper Lost" << endl;
	cin >> song;
	switch (song) {
	case 1:
		cout << "Were no strangers to love" << endl;
		cout << "You know the rules and so do I" << endl;
		cout << "A full commitments what Im thinking of" << endl;
		cout << "You wouldnt get this from any other guy" << endl;
		break;
	case 2:
		cout << "What doesnt kill you makes you wish you were dead." << endl;
		cout << "Got a hole in my soul growing deeper and deeper" << endl;
		cout << "And I cant take one more moment of this silence" << endl;
		cout << "The loneliness is haunting me" << endl;
		cout << "And the weight of the worlds getting harder to hold up" << endl;
		break;
	case 3:
		cout << "Watching haters wonder why Gambino got the game locked" << endl;
		cout << "Half-Thai thickie all she wanna do is Bangkok" << endl;
		cout << "Got her hair done French braids, now she A$AP" << endl;
		cout << "Bino so insensitive she asking Why you say that" << endl;
		break;
	case 4:
		cout << "My druggy" << endl;
		cout << "Love me" << endl;
		cout << "When Im ugly" << endl;
		cout << "Hug me" << endl;
		cout << "When Im bummy scummy" << endl;
		cout << "Im your hubby" << endl;
		cout << "Lets get lost lets get lost" << endl;
		break;
	}
}