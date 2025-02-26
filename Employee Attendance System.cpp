#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
#include <string.h>


using namespace std;


void authentication(string un, string pw);
void menu(bool authentic);

string username;
string password;
string designation;
string name; //fetched from db

char* getPassword() {
	const int maxSize = 10;
	char* pass = new char[maxSize];
	int i = 0;
	char c;

	cout << "\nPassword: ";

	while (true) {
		c = _getch();
		if (c == 13) {
			break;
		}
		else if (c == 8 && i > 0) {
			cout << "\b \b";
			i--;
		}
		else {
			pass[i] = c;
			i++;
			cout << "*";
		}
	}

	pass[i] = '\0';

	return pass;
}

void login() {
	cout << "\n************* LOGIN PAGE ************* " << endl;
	cout << "Username: ";
	cin >> username;
	char* pa = getPassword();
	size_t passLen = strlen(pa);
	password = (passLen, pa);

	authentication(username, password);

	delete[] pa;
}

void authentication(string un, string pw) {
	bool authentic{};
	if (un == "abhijeetsawai" && pw == "abhijeet") {
		cout << "\n\nWelcome! Admin";
		authentic = true;
	}
	else {
		cout << "\nInvalid Credentials";
		authentic = false;
	}

	menu(authentic);
}

void attendance() {
	time_t currentTime;
	time(&currentTime);

	char buffer[26];

	ctime_s(buffer, sizeof(buffer), &currentTime);
	cout << "Attendance recorded for" << designation << username << " at " << buffer;
}

void menu(bool authentic) {
	int menu_in = 0;
	if (authentic == true) {
		int menu = 0;
		do {
			cout << "\n1. Mark for Attendance. " << endl;
			cout << "2. Exit." << endl;
			cout << "Enter your input: ";
			cin >> menu_in;

			if (menu_in == 1 ) {
				//function for marking attendance3
				attendance();
				menu = 1;
			}
			else if (menu_in == 2) {
				menu = 1;
			}

			else {
				cout << "Invalid input. Please try again.";
			}
		} while (menu == 0);
		
	}
}

int main() {

	login();

}
