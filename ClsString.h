#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class ClsString
{
    string _str;

public:
    ClsString()
    {
        _str = "";
    }
    ClsString(string _str)
    {
        this->_str = _str;
    }
    void setString(string _str)
    {
        this->_str = _str;
    }

    string getString()
    {
        return _str;
    }
    // countEachWordInNewLine
    static int countEachWordInNewLine(string str)
    {
        string delim = " ";

        short pos = 0;
        int count = 0;
        string word;
        while ((pos = str.find(delim)) != std::string::npos)
        {
            word = str.substr(0, pos);
            if (word != "")
            {
                count++;
            }
            str.erase(0, pos + delim.length());
        }
        if (str != "")
        {

            count++;
        }
        return count;
    }
    int countEachWordInNewLine() // overloading
    {
        return countEachWordInNewLine(_str);
    }
    // printEachWordInNewLine
    static vector<string> printEachWordInNewLine(string str,string delim=" ")
    {
        short pos = 0;
        string word;
        vector<string> VecOFWords;
        while ((pos = str.find(delim)) != std::string::npos)
        {
            word = str.substr(0, pos);
            if (word != "")
            {
                VecOFWords.push_back(word);
            }
            str.erase(0, pos + delim.length());
        }
        if (str != "")
        {

            VecOFWords.push_back(str);
        }
        return VecOFWords;
    }
    vector<string> printEachWordInNewLine(string delim=" " ) // overloading
    {
        return printEachWordInNewLine(_str, delim);
    }
    // upper_Letters
    static string upper_Letters(string str)
    {

        for (int i = 0; i < str.length(); i++)
        {
            str[i] = toupper(str[i]);
        }
        return str;
    }
    string upper_Letters()
    {
        return upper_Letters(_str);
    }
    // lower_Letters
    static string lower_Letters(string input)
    {

        for (int i = 0; i < input.length(); i++)
        {
            input[i] = tolower(input[i]);
        }
        return input;
    }
    string lower_Letters()
    {
        return lower_Letters(_str);
    }

    // upper_Letters frist letter
    static string upper_firstLetter(string str)
    {
        str[0] = toupper(str[0]);
        return str;
    }
    string upper_firstLetter()
    {
        return upper_firstLetter(_str);
    }
    // lower_Letters frist letter
    static string lower_firstLetter(string str)
    {
        str[0] = tolower(str[0]);
        return str;
    }
    string lower_firstLetter()
    {
        return lower_firstLetter(_str);
    }
    // upper _latters in each word
    static string upper_FtristLetter_eachWord(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            str[0] = toupper(str[0]);
            if (str[i] == ' ')
            {
                str[i + 1] = toupper(str[i + 1]);
            }
        }
        return str;
    }
    string upper_FtristLetter_eachWord()
    {
        return upper_FtristLetter_eachWord(_str);
    }
    // reverse
    static string reverse(string str)
    {
        string rev = "";
        for (int i = str.length() - 1; i >= 0; i--)
        {
            rev += str[i];
        }
        return rev;
    }
    string reverse()
    {
        return reverse(_str);
    }
    // clear
    static string clear(string str)
    {
        str = "";
        return str;
    }
    string clear()
    {
        return clear(_str);
    }
    // replace
    static string replace(string str, char old, char neww)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == old)
            {
                str[i] = neww;
            }
        }
        return str;
    }
    string replace(char old, char neww)
    {
        return replace(_str, old, neww);
    }
    // replace_word
    static string replace_word(string str, string old, string neww)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (i + old.length() > str.length())
                break;
            if (str[i] != ' ')
                continue;
            if (str.substr(i, old.length()) == old)
            {
                str.replace(i, old.length(), neww);
            }
        }
        return str;
    }
    string replace_word(string old, string neww)
    {
        return replace_word(_str, old, neww);
    }
};
