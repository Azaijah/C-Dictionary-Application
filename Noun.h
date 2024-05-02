#pragma once

#include"Word.h"

using namespace std;

//This class is used to store Noun's.
class Noun : virtual public Word
{
public:
	Noun(string, string);
	bool isNoun() override;

	string getDefinition() override;

};
