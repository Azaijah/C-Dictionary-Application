#include"DictionarySystem.h"

//This function is used to get a selection from the user and ensures they enter an integer 
//(eg "Error" wil be printed to the screen if anything else is entered).
int DictionarySystem::getSelection()
{
	int selection;
	cout << endl << "Please enter your selection: ";
	cin >> selection;
	//Continously prompt the user to re-enter a value until an integer is provided.
	while (cin.fail())
	{
		cout << "Error: Invalid response, please enter a number corresponding to the options";
		cin.clear();
		cin.ignore(256, '\n');
		cout << endl << "Please enter your selection: ";
		cin >> selection;
	}

	return selection; //Once a valid selection is inputted return the selection.
}

//This function displays the options avaliable to the user.
void DictionarySystem::displayOptions()
{
	cout << endl << "Please select from the following options" << endl << endl;

	cout << "[1] - Find the definition for a word" << endl;
	cout << "[2] - Find words with more than 3 z's" << endl;
	cout << "[3] - Find words that contain a 'q' without a trailing 'u'" << endl;
	cout << "[4] - Find words that are palindromes" << endl;
	cout << "[5] - List all words that are nouns and verbs" << endl;
	cout << "[6] - Find all anagrams for a word" << endl;
	cout << "[7] - Play noun guessing game" << endl;
	cout << "[0] - To quit" << endl << endl;
}

//This function executes one of the options based upon the value passed into the function.
void DictionarySystem::executeOption(int selection)
{
	string word;

	switch (selection)
	{
	case 1:
		dictionary.findDefinition();
		cout << endl;
		break;
	case 2:
		dictionary.findWordWithMoreThanThreeZ();
		break;
	case 3:
		dictionary.findWordWithQandNoTrailingU();
		break;
	case 4:
		dictionary.findWordsThatArePalindrome();
		break;
	case 5:
		dictionary.findWordsThatAreVerbsAndNouns();
		break;
	case 6:
		cout << endl << "Please enter a word: ";
		cin >> word;
		dictionary.findAnagramsOfWord(word);
		break;
	case 7:
		dictionary.nounGuessingGame();
		break;
	default:
		cout << "No such options exists" << endl;
		break;
	}
}

void DictionarySystem::run() 
{
	
	if(dictionary.getLoaded() == false) 
	{
		cout << "Loading Dictionary Please Wait..." << endl;
		dictionary.loadDictionary("dictionary.txt"); //Loads a dictionary from a text file into the dictionary class, stored in a vector (see Dictionay.cpp).
		cout << "Loading complete" << endl;

		system("Pause");
	}


	while (true)
	{

		displayOptions(); //Display options avaliable to the user.

		int selection = getSelection(); //Get a selection from the user.
		
		if(selection != 0) 
		{
			executeOption(selection); //Execute the option based on the selection.
		}
		else
		{
			break;
		}
		


	}

}