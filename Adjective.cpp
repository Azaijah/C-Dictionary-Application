#include"Adjective.h"

Adjective::Adjective(string word, string definition) : Word (word, definition) {}

string Adjective::getDefinition()
{
	return "(adj.) " + Word::getDefinition();
}