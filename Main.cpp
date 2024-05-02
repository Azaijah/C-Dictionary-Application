#include"DictionarySystem.h"
#include"TriGramSystem.h"

int main()
{
	DictionarySystem dictSystem;
	TriGram triGramSystem;



	while (true) 
	{
		cout << endl;
		cout << "[1] - Access dictionary system" << endl;
		cout << "[2] - Access tri-gram system" << endl;
		cout << "[0] - To exit" << endl;

		int selection;

		cout << "Enter your selection: ";
		cin >> selection;

		if (selection == 1) { cout << endl; dictSystem.run(); }
		else if (selection == 2) { cout << endl; triGramSystem.run(); }
		else if (selection == 0) { return 0; }
		else { cout << "Invalid Selection" << endl << "Please try again: " << endl; }
	}



}

