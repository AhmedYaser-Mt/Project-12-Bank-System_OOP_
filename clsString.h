#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

class clsString
{
	string _Value;

public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static short CountWords(string S1)
	{
		string delim = " ";
		short pos = 0;
		string sWord = "";
		short Counter = 0;

		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
			{
				Counter++;
			}

			S1.erase(0, pos + delim.length());
		}

		if (S1 != "")
		{
			Counter++;
		}

		return Counter;
	}

	short CountWords()
	{
		return CountWords(_Value);
	}

	static void PrintFirstLetters(string Word)
	{
		bool IsFirstLetter = true;

		cout << "\nFirst Letters of this string :\n";

		for (short i = 0;i < Word.length();i++)
		{
			if (Word[i] != ' ' && IsFirstLetter)
				cout << Word[i] << "\t";

			IsFirstLetter = (Word[i] == ' ' ? true : false);
		}

	}

	void PrintFirstLetters()
	{
		PrintFirstLetters(_Value);
	}

	static string UpperFirstLetterOfEachWord(string Word)
	{
		bool IsFirstLetter = true;

		for (short i = 0;i < Word.length();i++)
		{
			if ((Word[i] != ' ' && IsFirstLetter) && (islower(Word[i])))
			{
				Word[i] = toupper(Word[i]);
			}

			IsFirstLetter = (Word[i] == ' ' ? true : false);
		}

		return Word;
	}

	void UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string Word)
	{
		bool IsFirstLetter = true;

		for (short i = 0;i < Word.length();i++)
		{
			if ((Word[i] != ' ' && IsFirstLetter) && (isupper(Word[i])))
			{
				Word[i] = tolower(Word[i]);
			}

			IsFirstLetter = (Word[i] == ' ' ? true : false);
		}

		return Word;
	}

	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	static string UpperAllString(string Word)
	{
		for (short i = 0;i < Word.length();i++)
		{
			if ((islower(Word[i])))
			{
				Word[i] = toupper(Word[i]);
			}
		}

		return Word;
	}

	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	static string LowerAllString(string Word)
	{
		for (short i = 0;i < Word.length();i++)
		{
			if ((isupper(Word[i])))
			{
				Word[i] = tolower(Word[i]);
			}
		}

		return Word;
	}

	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

	static char InvertLetterCase(char Character)
	{
		return isupper(Character) ? tolower(Character) : toupper(Character);
	}

	static string InvertAllLettersCase(string Word)
	{
		for (short i = 0;i < Word.length();i++)
		{
			Word[i] = InvertLetterCase(Word[i]);
		}

		return Word;
	}

	void InvertAllLettersCase()
	{
		_Value = InvertAllLettersCase(_Value);
	}

	static bool IsVowel(char Ch1)
	{
		Ch1 = tolower(Ch1);

		return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
	}

	static string TrimLeft(string S1)
	{
		for (short i = 0;i < S1.length();i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}
		return "";
	}

	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string S1)
	{
		for (short i = (S1.length() - 1);i >= 0;i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}

		return "";
	}

	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 2 };

	static short CountLetters(string Word, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		if (WhatToCount == enWhatToCount::All)
			return Word.length();

		short Counter = 0;

		for (short i = 0;i < Word.length();i++)
		{

			if (isupper(Word[i]) && WhatToCount == enWhatToCount::CapitalLetters)
				Counter++;

			if (islower(Word[i]) && WhatToCount == enWhatToCount::SmallLetters)
				Counter++;
		}

		return Counter;
	}

	short CountLetters(enWhatToCount WhatToCount = enWhatToCount::All)
	{
		return CountLetters(_Value, WhatToCount);
	}

	static short CountCapitalLetters(string Word)
	{
		short Counter = 0;

		for (short i = 0;i < Word.length();i++)
		{
			if (isupper(Word[i]))
				Counter++;
		}

		return Counter;
	}

	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static short CountSmallLetters(string Word)
	{
		short Counter = 0;

		for (short i = 0;i < Word.length();i++)
		{
			if (islower(Word[i]))
				Counter++;
		}

		return Counter;
	}

	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	static short Length(string Word)
	{
		return Word.length();
	}

	short Length()
	{
		return _Value.length();
	}

	static short CountSpecificLetter(string Word, char Character, bool MatchCase = true)
	{
		short Counter = 0;

		for (short i = 0;i < Word.length();i++)
		{
			if (MatchCase)
			{
				if (Word[i] == Character)
					Counter++;
			}
			else
			{
				if (tolower(Word[i]) == tolower(Character))
					Counter++;
			}
		}

		return Counter;
	}

	short CountSpecificLetter(char Character, bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, Character, MatchCase);
	}

	static short CountVowels(string Word)
	{
		short Counter = 0;

		for (short i = 0;i < Word.length();i++)
		{
			if (IsVowel(Word[i]))
				Counter++;
		}

		return Counter;
	}

	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static void PrintVowels(string Word)
	{
		cout << "\nVowels in string are : ";

		for (short i = 0;i < Word.length();i++)
		{
			if (IsVowel(Word[i]))
				cout << Word[i] << "    ";
		}
		cout << endl;
	}

	void PrintVowels()
	{
		PrintVowels(_Value);
	}

	static vector <string> Split(string S1, string delim)
	{
		short pos = 0;
		string sWord = "";
		vector <string> vString;

		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);
			
			vString.push_back(sWord);
			

			S1.erase(0, pos + delim.length());
		}

		if (S1 != "")
		{
			vString.push_back(S1);
		}

		return vString;
	}

	vector <string> Split(string delim)
	{
		return Split(_Value, delim);
	}

	static string JoinString(vector <string>& vString, string Delim)
	{
		string S1 = "";

		for (const string& Word : vString)
		{
			S1 += Word + Delim;
		}

		return (S1.substr(0, S1.length() - Delim.length()));
	}

	static string JoinString(string ArrString[], short Length, string Delim)
	{
		string S1 = "";

		for (short i = 0;i < Length;i++)
		{
			S1 += ArrString[i] + Delim;
		}

		return (S1.substr(0, S1.length() - Delim.length()));
	}

	static void PrintEachWordInString(string S1)
	{
		cout << "\nYour string Words are :\n\n";

		string delim = " ";
		short pos = 0;
		string sWord = "";

		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
				cout << sWord << endl;

			S1.erase(0, pos + delim.length());
		}

		if (S1 != "")
			cout << S1 << endl;
	}

	void PrintEachWordInString()
	{
		PrintEachWordInString(_Value);
	}

	static string Trim(string S1)
	{
		return TrimLeft(TrimRight(S1));
	}

	void Trim()
	{
		_Value = Trim(_Value);
	}

	static string ReverseWordsInString(string S1)
	{
		vector <string> vString = Split(S1, " ");

		string S2 = "";

		vector <string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;

			S2 += *iter + " ";
		}

		S2 = S2.substr(0, S2.length() - 1);
		return S2;
	}

	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}

	static string ReplaceWord(string S1, string StringToReplace, string UpdateTo, bool Match = true)
	{
		vector <string> vString = Split(S1, " ");

		for (string& Word : vString)
		{
			if (Match)
			{
				if (Word == StringToReplace)
					Word = UpdateTo;
			}
			else
			{
				if (LowerAllString(Word) == LowerAllString(StringToReplace))
					Word = UpdateTo;
			}
		}

		return JoinString(vString, " ");
	}

	void ReplaceWord(string StringToReplace, string UpdateTo, bool Match = true)
	{
		_Value = ReplaceWord(_Value, StringToReplace, UpdateTo, Match);
	}

	static string RemovePunctuations(string S1)
	{
		string S2 = "";

		for (short i = 0;i < S1.length();i++)
		{
			if (!ispunct(S1[i]))
				S2 += S1[i];
		}

		return S2;
	}

	void RemovePunctuations()
	{
		_Value = RemovePunctuations(_Value);
	}
};

