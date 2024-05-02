#pragma once

#include<iostream>
#include<string>
#include <fstream>
#include<algorithm>
#include<vector>
#include <utility>
#include<random>

using namespace std;

class TriGram
{
public:
	//TriGram();
	void readFile(string); //Reads a file and places the contents into a string.
	void preProcessing(string&); //Used to prepare a string for tri-gram analysis (removes no alphabetical characters except spaces).
	void displayOptions(); //Used to display menu options to the user.
	int getSelection(); //Used to get a selection from the user.
	void executeOption(int); //Used to execute one of the systems features based on the selection from the user (passed in as an int).
	void run(); //Runs the tri-grams systems core features.
	vector<char> getThreeMostLikelyCharToAppearAfterAnyTwoChar(char, char); //Used to find the most likely char to appear after any two char's passed into the function.
	int getIndex(char); //Used to increase the count of a character in the alphabet (used by getThreeMostLikelyCharToAppearAfterAnyTwoChar(); when it finds a character after the any two chars passed in.
	void generateEnglishSoundingWord(); //Used to generate an english sounding word based on tra-gram analysis of a string (uses getThreeMostLikelyCharToAppearAfterAnyTwoChar(); for this purpose).

private:
	string contents = ""; //Used to store the contents of a txt file to be used for tri-gram analysis.

};


