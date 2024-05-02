#include"TriGramSystem.h"

//This function simply reads in a files contents to a string.
void TriGram::readFile(string filename)
{

	ifstream myfile(filename);

	if (myfile.is_open())
	{
		
		string line;

		while (!myfile.eof())
		{
			getline(myfile, line);

			contents += ' ' + line;

		}

	}
	else
	{
		cout << "Error: Cannot Open File" << endl;
	}
}

//This function removes all none alphabetical characters except spaces from a string.
void TriGram::preProcessing(string& content)
{
	char toBeRemoved;

	for (int i = 0; i < content.size(); ++i)
	{
		//if the character is not alphabetical mark it to be removed else continue from the start of the for loop.
		if (!((content[i] >= 'a' && content[i] <= 'z') || (content[i] >= 'A' && content[i] <= 'Z') || (content[i] == ' ')))
		{
			toBeRemoved = content[i];
		}
		else
		{
			continue; 
		}

		content.erase(remove(content.begin(), content.end(), toBeRemoved), content.end()); //remove the marked character from the string

	}
}


vector<char> TriGram::getThreeMostLikelyCharToAppearAfterAnyTwoChar(char a, char b)
{	

	vector<char> topThree; //Used to store the top 3 characters found after any two random char's passed in

	int charCount[27] = { 0 }; //Used to increase the count for each word in alphabet if it is found after the two chars (index 0 = space, index 1 = a, index 2 = b....).
	

	char c = NULL; //used to stores a character if it is found after the any two chars
	int index = -1;

	//Iterate over each character if the current one and the next one is equal to the any two char's passed in set "c" to the char after the any two chars and get the index of that character
	//Increment the character count based off its index in "charCount".
	for (int i = 0; i < contents.size(); ++i) 
	{
		if(contents[i] == a && contents[i+1] == b)
		{

			index = -1;

			c =	contents[i + 2];

			index = getIndex(c);

			if (index != -1)
			{
				charCount[index]++;
			}			
		}
	}

	//The following code  associates a characters count with its actual character.
	typedef std::pair<char, int> LetterCountPair;
	std::vector<LetterCountPair> letterCountPair; //Stores the character and count pair.
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	int counter = 1; //Used to refer to the index of the character starting from 'a' (index 1).
	//For each character in the alphabet associate it with its character count based on its index in "charCount"
	for(char& c: alphabet) 
	{

		letterCountPair.push_back(make_pair(c, charCount[counter]));
		counter++;

	}

	//The following code sorts the character pair count based on the characters count.
	std::sort(letterCountPair.rbegin(), letterCountPair.rend(), [](auto &left, auto &right) {
		return left.second < right.second;
	});

	for (int i = 23; i > 0; --i) { letterCountPair.pop_back(); } //This piece of code strips all characters from the character pair count except the top 3.

	//The following code pushes the top 3 characters into the variable "topThree"
	for (std::vector<LetterCountPair>::const_iterator iter = letterCountPair.begin();
		iter != letterCountPair.end(); ++iter)
	{
		topThree.push_back(iter->first);
	}

	return topThree; //The top 3 characters are returned.
}

//Get the index of a character in terms of its alphabetical order e.g. a = index 1, b = index 2 .... 
int TriGram::getIndex(char a)
{
	int index = -1;
	int currentCharCode = (int)a;

	if (currentCharCode == (int)' ') { index = 0; }
	else if ((int)'a' <= currentCharCode <= (int)'z')
	{
		index = currentCharCode - (int)'a' + 1;
	}
	return index;
}


void TriGram::generateEnglishSoundingWord()
{
	//This code is used in the generation of random numbers.
	random_device randDev;
	mt19937 eng(randDev());


	//The following code generates a random number between 0-25 (representing the indexes of the 26 letters in the alphabet - stored in the string "alphabet").
	//Two numbers are set to a random number in this range and latter used to randomly select to characters from the alphabet.
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	uniform_int_distribution<> distrAlpha(0, 25);
	int randNum1;
	int randNum2;
	randNum1 = distrAlpha(eng);
	randNum2 = distrAlpha(eng);

	//The following code generates a random number between 1 and 3 used to determine the length of the to be created english sounding word
	//1 = 3 letter word, 2 = 6 letter word and 3 = 9 letter word (words are built in blocks of 3's using the any two char's and the highest char to appear after them.
	uniform_int_distribution<> distrWordLen(1, 3);
	int wordlen;
	wordlen = distrWordLen(eng);


	string word; //Used to store an english 'sounding' word.
	vector<char> topThree; //Stores the top 3 characters returned by getThreeMostLikelyCharToAppearAfterAnyTwoChar();


	//The following code intiates the creation of an english sounding word by using two random char's decided by the random number generator and forming a 3 letter block.
	topThree = getThreeMostLikelyCharToAppearAfterAnyTwoChar(alphabet[randNum1], alphabet[randNum2]);

	word += alphabet[randNum1];
	word += alphabet[randNum2];
	word += topThree[0];
	

	//If the word to be created is 3 letters e.g. wordlen = 1, the following code is skipped and the word is printed below.
	//If wordlen = 2,3 meaning the word will be a 6 or 9 letter word, the last two chars in "word" (and the highest word to appear after them)
	//are used to create a new 3 letter block until the word is printed.
	for(int i = wordlen - 1; i > 0; i--) 
	{

		int x = 1;

		topThree = getThreeMostLikelyCharToAppearAfterAnyTwoChar(word[x], topThree[0]);

		word += alphabet[randNum1];
		word += alphabet[randNum2];
		word += topThree[0];

		x += 3;
	}


	cout << "Word: " << word << endl; //The english sounding word is printed.
	

}

void TriGram::displayOptions()
{
	cout << endl << "Please select from the following options" << endl << endl;

	cout << "[1] - Generate 10 random english sounding words" << endl;
	cout << "[0] - To quit" << endl;

}

int TriGram::getSelection()
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

void TriGram::executeOption(int selection)
{
	string word;

	switch (selection)
	{
	case 1:
		for(int i = 10; i > 0; i--) { generateEnglishSoundingWord(); }
		cout << endl;
		break;

	default:
		cout << "No such options exists" << endl;
		break;
	}
}

void TriGram::run() 
{
	
	cout << "Loading/Preprocessing..." << endl;
	readFile("dictionary.txt");
	preProcessing(contents);
	system("Pause");

	while (true)
	{

		displayOptions(); //Display options avaliable to the user.

		int selection = getSelection(); //Get a selection from the user.

		if (selection != 0)
		{
			executeOption(selection); //Execute the option based on the selection.
		}
		else
		{
			break;
		}



	}



}
