
#include "Functions.h"



char getLetter(int index)
{
    return base64[index];
}



string codeBase64(char first, char second, char third) {
    string result = "";
    char temp, temp1;


        temp = (char)first >> 2;

        result += getLetter(temp);


        temp = (((char)first & 3) << 4) | ((char)second >> 4);

        result += getLetter(temp);

        if (second != '\0')
        {
            temp = (((char)second & 15) << 2) | ((char)third >> 6);

            result += getLetter(temp);
        }

        if (third != '\0')
        {
            temp = (char)third & 63;
            result += getLetter(temp);
        }

        if (second == '\0')
        {
            result += "==";
        }
        else
        if (third == '\0')
        {
            result += "=";
        }

        return result;

    }



    string coding(string input) {
        string result = "";

        for (int i = 0; i < input.length() - (input.length() % 3); i += 3)
        {
            result += codeBase64(input[i], input[i+1], input[i+2]);
        }

        if (input.length() % 3 != 0)
        {
            char letter2, letter3;

            if (input[input.length() - input.length() % 3 + 1] == '\0') {
                letter2 = '\0';
                letter3 = '\0';
            } else if (input[input.length() - input.length() % 3 + 2] == '\0') {
                letter2 = input[input.length() - input.length() % 3 + 1];
                letter3 = '\0';
            }

            result += codeBase64(input[input.length() - input.length() % 3], letter2, letter3);
        }
        return result;
}

char getIndex(char letter)
{
    for (int i = 0; i < base64.length(); ++i)
    {
        if (base64[i] == letter)
        {
            return i;
        }
    }
}

string decoding(char first, char second, char third, char fourth)
{
    string result = "";
    first = getIndex(first);
    second = getIndex(second);
    third = getIndex(third);
    fourth = getIndex(fourth);
    char temp = 0;

    temp = (first << 2 | second >> 4);
    result += temp;

    temp = (second << 4) | (third >> 2);

    if (temp != 61)
    {
        result += temp;
    }
    else
    {
        return result;
    }

    temp = (third << 6) | fourth;
    if (temp != 61)
    {
        result += temp;
    }
    else
    {
        return result;
    }

    return result;


}

string DecodeBase64(string input)
{
    string result = "";
    for (int i = 0; i < input.length() - input.length() % 4; i += 4)
    {
        result += decoding(input[i], input[i+1], input[i + 2], input[i + 3]);
    }



    return result;
    
}
