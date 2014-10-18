#include <iostream>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istringstream;

// Check if a string is entirely alphabetic
bool is_alphabetic(const string& string_to_check)
{
	// Cycles through each letter of the string checking for digits and punctuation
	for (const auto& letter : string_to_check)
	{
		if (isdigit(letter) || ispunct(letter))
		{
			return 0;
		}
	}
	return 1;
}

// Checks if a character is a vowel or not
bool is_vowel(const char& character_to_check)
{
	switch (character_to_check)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return 1;
		break;
	default:
		return 0;
		break;
	}
}

// Converts string to all lowercase. Ignores punctuation and blank spaces
void convert_to_lowercase(string& word_to_convert)
{
	for (auto& letter : word_to_convert)
	{
		if (isupper(letter))
		{
			letter = tolower(letter);
		}
	}
}

// Converts a string to pig latin
string convert_to_pig_latin(const string& word_to_convert)
{
	string pig_latin;
	char first_letter_of_word = word_to_convert.front(); // Obtain first letter of the word
	if (is_vowel(first_letter_of_word)) // Check if first letter is a vowel
	{
		// If first letter is a vowel add the word + '-way' to pig latin
		pig_latin = word_to_convert + "-way";
	}
	else
	{
		string first_letter(1, first_letter_of_word); // Convert first letter of the word to a string
		pig_latin = word_to_convert; 
		pig_latin.erase(0, 1); // Remove the first letter in pig latin
		pig_latin += "-" + first_letter + "ay"; // Add a '-' + the first letter of the word + 'ay' to pig latin
	}
	return pig_latin;
}

int main()
{
	cout << "Please enter an alphabetic senetence:" << endl;
	string sentence;
	getline(cin, sentence);

	// Check if sentence is blank or is not alphabetic
	while (sentence == "" || !is_alphabetic(sentence))
	{
		cout << "\nThe sentence is either blank or not completely alphabetic..." << endl;
		cout << "Please enter an alphabetic senetence:" << endl;
		getline(cin, sentence);
	}

	convert_to_lowercase(sentence);
	istringstream iss(sentence);
	string word;

	// Cycle through each word in the sentence and convert to pig latin
	while (iss >> word)
	{
		cout << convert_to_pig_latin(word) << " ";
	}
	cout << endl;
	return 0;
}