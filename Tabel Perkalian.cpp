#include <iostream>
#include <windows.h>
using namespace std;

int main() {
	
	HWND command_prompt = GetConsoleWindow();
	
	// Option Tabel Perkalian
	int option;
	cout << "Inputkan angka perkalian yang ingin ditampilkan: "; cin >> option;
	if (option > 10) {
		cout << "Error: Input anda tidak valid (Angka: 1 - 10)";
		return 1;
	} else if (cin.fail()) {
		cout << "Error: Input anda tidak valid (Angka: 1 - 10)";
		return 1;		
	} else if (option == 10) {
		SetWindowPos(command_prompt, 0, 100, 100, 1100, 600, SWP_NOZORDER);
	}
	
	
	// Header Tabel Perkalian
	cout << "\n\nMenampilkan Tabel Perkalian sampai dengan angka " << option << endl;
	for (int c = 1; c <= option+2; c++) {
		cout << " -------";
	}	
	cout << "\nX\t|\t";
	for (int x = 1; x <= option; x++) {
		cout << x << "\t";
	}
	cout << "| --> Kolom Tabel Perkalian";
	cout <<endl;
	for (int y = 1; y <= option+2; y++) {
		cout << " -------";
	}
	
	// Main Tabel Perkalian
	cout << endl;
	for (int a = 1; a <= option; a++) {
		cout << a << "\t|\t";
		for (int b = 1; b <= option; b++) {
			cout << a*b << "\t";
		}
		if(a <= option-1) {
			cout << "| -->> Perkalian Angka " << a << "\n" <<endl;	
		} else if(a >= option-1) {
			cout << "| -->> Perkalian Angka " << a << endl;
		}
	}
	
	// Footer Tabel Perkalian
	for (int z = 1; z <= option+2; z++) {
		cout << " -------";
	}
	cout << "\n    |\n    |\n    o--> Baris Tabel Perkalian\n\n";
	
	
//	for(int a = 1; a < 10; a++) {
//		for (int b = 1; b < 10; b++) {
//			cout << a*b << "\t";
//		}
//		cout << "\n" << endl;
//	}
}
