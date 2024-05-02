#pragma once
#include"Noun.h"

using namespace std;

//This class is used to store ProperNoun's.
class ProperNoun : public Noun
{
public:
	ProperNoun(string, string);

	string getDefinition() override;
	string getWord() override; 

};
