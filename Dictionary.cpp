#include "Dictionary.h"

//This file contains the implementation for the Dictionary Class. 

//Used to load a dictionary in .txt format into the collectionOfWords vector.
void Dictionary::loadDictionary(string filename)
{
	//Variables related to the file.
	ifstream myfile(filename);

	//Variables used to temporarily store data extracted from the file.  
	string word;
	string definition;
	string type;
	string whitespace;
	
	//Constants used to identify the type of word being read in from the dictionary file.
	const string verbType = "v";
	const string nounType = "n";
	const string adverbType = "adv";
	const string adjectiveType = "adj";
	const string prepositionType = "prep";
	const string properNounType = "pn";
	const string NounAndVerbType = "n_and_v";
	const string MiscWordType = "misc";

	if (myfile.is_open())
	{
		//extracts each piece of information for a word per loop (until the end of the file).
		//Each piece of information (word, definition and type) is passed into a word object which acts as a buffer before
		//being copied into the collection of words.
		while (!myfile.eof()) 
		{
			getline(myfile, word);
			getline(myfile, definition);
			getline(myfile, type);
			getline(myfile, whitespace);

			//collectionOfWords.push_back(new Word(word, definition)); 

			if(type == verbType) { collectionOfWords.push_back(new Verb(word, definition)); }
			if(type == nounType) { collectionOfWords.push_back(new Noun(word, definition)); }
			if(type == adverbType) { collectionOfWords.push_back(new Adverb(word, definition)); }
			if(type == adjectiveType) { collectionOfWords.push_back(new Adjective(word, definition)); }
			if(type == prepositionType) { collectionOfWords.push_back(new Preposition(word, definition)); }
			if(type == properNounType) { collectionOfWords.push_back(new ProperNoun(word, definition)); }
			if(type == NounAndVerbType) { collectionOfWords.push_back(new VerbAndNoun(word, definition)); }
			if(type == MiscWordType) { collectionOfWords.push_back(new MiscWord(word, definition)); }
			
			loaded = true;

		}
			
	}
	else
	{
		cout << "Error: Cannot Open File" << endl;
	}
}

bool Dictionary::getLoaded()
{
	return loaded;
}

//Used to find the definition of a word based on the string passed in.
void Dictionary::findDefinition()
{
	//Loop through each word in the collection of words and test if the match the string passed into the function.
	//If it match prints the definition to the screen.

	string search;

	cout << endl << "Please enter a word: ";
	cin >> search;


	bool wordFound = false;

	for (Word *word : collectionOfWords)
	{
		if (word->getWord() == search)
		{
			cout << endl;
			word->printDefinition();
			cout << endl;
			system("pause");
			wordFound = true;
		}
	}

	if(wordFound == false) 
	{
		cout << endl << "Word Not Found" << endl;
	}
}

//Finds words with more than 3 z's and prints them to the screen.
void Dictionary::findWordWithMoreThanThreeZ()
{
	//Loop through each word in the collection of words and then loop through each character per word. 
	//If a character matches 'z' increment the counter.
	//If the counter reaches greater than 3 before the end of the word, the word is printed too the screen.
	for (Word *word : collectionOfWords)
	{
		int count;
		count = 0;
		for (int i = 0; i < (int)word->getWord().length(); i++)
		{
			if (word->getWord()[i] == 'z')
			{
				++count;
			}
		}
		if (count > 3)
		{ 
			cout << word->getWord() << endl;
		}
			
	}		
}

//Finds words with a q but no trailing u.
void Dictionary::findWordWithQandNoTrailingU()
{
	//Loops through each word in the collection of words and then loops through each character per word.
	//If the current letter being iterated over is equal to 'q' and the current character plus 1 (eg the next character in the word)
	//if its not equal to 'u' print the word.
	for (Word *word : collectionOfWords)
	{
		int count;
		count = 0;
		for (int i = 0; i < (int)word->getWord().length(); i++) 
		{
			if(word->getWord()[i] == 'q' && word->getWord()[i+1] != 'u') 
			{
				cout << word->getWord() << endl;
			}
		}

	}
}

//Finds words that are palindromes
void Dictionary::findWordsThatArePalindrome() 
{
//Loops through each word in the collection of words
//Uses the word isPalindrome() function to see if the word is a Palindrome or not
//If it is the word is printed.
	for (Word *word : collectionOfWords) 
	{
		if(word->isPalindrome() == true) 
		{
			cout << word->getWord() << endl;
		}
	}

}

//This function returns a pointer to a word object if the word objects word matches the string passed into the function.
Word *Dictionary::findWord(string search)
{

	//Loops through each word in the collection of words
	//If the current word objects word matches the string passed in return a pointer to that word object.
	//If no word is found a nullptr is returned.

	bool wordFound = false;

	
	for(Word *word : collectionOfWords) 
	{
		if (word->getWord() == search)
		{
			wordFound = true;
			return word;
		}
	}
	if(wordFound == false) 
	{
		return nullptr;
	}
}

//Finds words that are both nouns and verbs.
void Dictionary::findWordsThatAreVerbsAndNouns()
{
	//Loops through each word in the collection of words
	//If the name of the class of the current word object matches the VerbAndNoun class name 
	//that word is printed to the user.
	for (Word *word : collectionOfWords)
	{
		if(typeid(*word).name() == typeid(VerbAndNoun).name())
		{
			cout << word->getWord() << endl;
		}
	}

}

//Finds anagrams of the word/string passed into the function.
void Dictionary::findAnagramsOfWord(string _word)
{
	string w1, w2;

	//Loops through each word in the collection of words
	//If the word passed into the function is the same length as the current word objects word there is possbility the word is an anagram.
	//The word passed into the funciton and he word objects word are then both sorted into alphabetical order.
	//If they match the word is an anagram and is printed to the screen.
	for (Word *word : collectionOfWords)
	{
		if (_word.length() == word->getWord().length())
		{
			w1 = _word;
			w2 = word->getWord();

			sort(w1.begin(), w1.end());
			sort(w2.begin(), w2.end());

			if (w1 == w2 && word->getWord() != _word) 
			{
				cout << word->getWord() << endl;
			}
			
		}
	}
}

//This function displays a definition of a noun to the user and gives them 3 attempts to guess the word of the definition.
void Dictionary::nounGuessingGame()
{
	vector<Word*> nouns;
	string word;

	//Loops through each word in the collection of words
	//If the current word object is a noun store a pointer to it in "nouns"
	for (Word *word : collectionOfWords)
	{
		if(word->isNoun() == true && word->isVerb() == false) 
		{
			nouns.push_back(word);
		}
	}
	
	//Generate a random number between the range of 0 and the total size of nouns (used to randomly select a noun).
	random_device randDev;
	mt19937 eng(randDev());
	uniform_int_distribution<> distr(0, (int)nouns.size() - 1);
	int randNum = distr(eng);


	cout << nouns[randNum]->getDefinition() << endl; //Print of definition of the noun to the user.

	//Give the user 3 attempts to correctly guess the noun.
	//If the users input matches the word of the word/noun object print correct and break out
	//If the users input is wrong print wrong and let them retry until there is no more attempts.
	for (int i = 1; i < 4; i++) 
	{
		cout << endl << "Attempt: " << i << endl << "Enter word that matches the definition: ";
		cin >> word;

		if (nouns[randNum]->getWord() == word)
		{
			cout << endl << "CORRECT !!!" << endl;
			break;
		}
		else
		{ 
			cout << endl << "WRONG !!!" << endl; 
			if(i != 3) 
			{
				cout << "Letter: " << i << " is " << nouns[randNum]->getWord()[i-1];
			}
			else { cout << "Game Over" << endl << "The word was: " << nouns[randNum]->getWord() << endl; }
			
		}

	}

	
	

	

}

