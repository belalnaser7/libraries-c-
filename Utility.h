#pragma once
#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>
#include "ClsDate.h"
using namespace std;
class clsUtility {
   
    	enum EnprimeOrNot { Prime = 1, NotPrime = 2 };
	 static EnprimeOrNot ChickPrimeNumber(int num) {  //function to check prime number
		int HalfNumber = num / 2;
		for (int i = 2; i <= HalfNumber; i++) {
			if (num % i == 0)
				return EnprimeOrNot::NotPrime;
		}
		return EnprimeOrNot::Prime;
	}
public:
	static void Srand() {
		srand((unsigned)time(NULL));
	}

static string CheckPrimeNumber(int num) {
        if (ChickPrimeNumber(num) == EnprimeOrNot::Prime)
            return " this is Prime Number";
        else
            return " this is Not Prime Number";
}

	static int GetSumOfDigits(int num) {  //function to get sum of digits
		int Reminder = 0, sum = 0;
		while (num != 0) {
			Reminder = num % 10;
			num = num / 10;
			sum += Reminder;
		}
		return sum;
	}
    
    static int GetProductOfDigits(int num) {  //function to get product of digits
        int Reminder = 0, Product = 1;
        while (num != 0) {
            Reminder = num % 10;
            num = num / 10;
            Product *= Reminder;
        }
        return Product;
    }

    static int GetNumberOfDigits(int num) {  //function to get number of digits
        int Counter = 0;
        while (num != 0) {
            num = num / 10;
            Counter++;
        }
        return Counter;
    }

    
	static int GetFrequency(int num, int digit) { //function to get frequency
		int Reminder = 0, Freq = 0;
		while (num != 0) {
			Reminder = num % 10;
			num = num / 10;
			if (Reminder == digit) {
				Freq++;
			}
		}
		return Freq;
	}

	static int ReverseNumber(int num) {
		int Reminder = 0, NumberReversed = 0;
		while (num != 0) {
			Reminder = num % 10;
			num = num / 10;
			NumberReversed = Reminder + NumberReversed * 10;
		}
		return NumberReversed;
	}

    static int reverseNumber(int num) {
        int Reminder = 0;
        string str = "";
        while (num != 0) {
            Reminder = num % 10;
            num = num / 10;
            str = str + to_string(Reminder);
        }
        return stoi(str);
    }

	static bool CheckPalindromeNumber(int num) { //function to check palindrome
		return(num == ReverseNumber(num));
	}

	static string EncryptText(string Text, short EncryptionKey) {//function to encrypt text by adding encryption key
		for (int i = 0; i <= Text.length(); i++)
			Text[i] = char((int)Text[i] + EncryptionKey);
		return Text;
	}

	static string DecryptText(string Text, short EncryptionKey) { //function to decrypt text by subtracting encryption key
		for (int i = 0; i <= Text.length(); i++)
			Text[i] = char((int)Text[i] - EncryptionKey);
		return Text;
	}

	static int RandomNumber(int From, int To) { //function to get random number
		int RandNum = rand() % (To - From + 1) + From;
		return RandNum;
	}
 enum enCharacterType { SmallLetter = 1, CapitalLetter = 2, SpecialChar = 3, Digit = 4, All = 5 };
	static char GetRandomCharacter(enCharacterType CharacterType) { //function to get random character
		switch (CharacterType) {
		case enCharacterType::SmallLetter:
			return char(RandomNumber(97, 122));
		case enCharacterType::CapitalLetter:
			return char(RandomNumber(65, 90));
		case enCharacterType::SpecialChar:
			return char(RandomNumber(33, 47));
		case enCharacterType::Digit:
			return char(RandomNumber(48, 57));
		default:
			return char(RandomNumber(33, 122));
		}
	}

	static bool CheckPerfectNumber(int num) {
		int sum = 0;
		for (int i = 1; i < num; i++) {
			if (num % i == 0)
				sum += i;
		}
		return sum == num;
	}
private:
	static string GenerateWord(enCharacterType CharacterType, short Length) {
		string word;
		for (int i = 1; i <= Length; i++) {
			word = word + GetRandomCharacter(CharacterType);
		}
		return word;
	}
public:
	static string GenerateKey() {
		string FullKey;
		FullKey = GenerateWord(enCharacterType::CapitalLetter, 4) + "-";
		FullKey = FullKey + GenerateWord(enCharacterType::CapitalLetter, 4) + "-";
		FullKey = FullKey + GenerateWord(enCharacterType::CapitalLetter, 4) + "-";
		FullKey = FullKey + GenerateWord(enCharacterType::CapitalLetter, 4);
		return FullKey;

	}
	static void Swap(int& num1, int& num2) {
		int ToSwap;
		ToSwap = num1;
		num1 = num2;
		num2 = ToSwap;
	}

    static void Swap(string& num1, string& num2) {
		string ToSwap;
		ToSwap = num1;
		num1 = num2;
		num2 = ToSwap;
	}
    static void Swap(char& num1, char& num2) {
        char ToSwap;
        ToSwap = num1;
        num1 = num2;
        num2 = ToSwap;
    }
    static void swap(ClsDate& num1, ClsDate& num2) {
        ClsDate ToSwap;
        ToSwap = num1;
        num1 = num2;
        num2 = ToSwap;
    }
	enum enNumberTypeEO { Even = 1, Odd = 2 };
	static enNumberTypeEO CheckNumberType(int num) {
		if (num % 2 != 0)
			return enNumberTypeEO::Odd;
		else
			return enNumberTypeEO::Even;
	}



      static  void ShuffleArray(int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static void ShuffleArray(string arr[100], int arrLength)
{
    for (int i = arrLength - 1; i > 0; i--)
    {
        int j = RandomNumber(0, i);
        Swap(arr[i], arr[j]);
    }
}


    static string  Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;

    }
};