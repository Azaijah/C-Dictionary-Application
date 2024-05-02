#pragma once
#include"Word.h"

using namespace std;


//This class is used to store Adverb's.
class Adverb : public Word
{
public:
	Adverb(string, string);

	string getDefinition() override;

private:

};

