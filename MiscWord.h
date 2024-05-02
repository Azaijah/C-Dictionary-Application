#pragma once
#include"Word.h"

using namespace std;

//This class is used to store MiscWord's.
class MiscWord : public Word
{
public:
	MiscWord(string, string);

	string getDefinition() override;

private:

};
