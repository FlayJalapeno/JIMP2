//
// Created by Kornel on 08.03.2018.
//

#include<iostream>
#include "Palindrome.h"
#include<string>

bool is_palindrome(std::string str)
{
    int i,j;
    for(i = 0, j = str.length() - 1; i <= j; i++, j--)
    {
        if(str[i] != str[j])
            break;
    }
    if(i<j)
        return false;
    else
        return true;
}