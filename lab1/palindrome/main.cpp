//
// Created by Kornel on 08.03.2018.
//
#include<iostream>
#include<Palindrome.h>

int main()
{
    std::string word = "abccba";
    std::cout<<"Odpowiedzia na pytanie, czy wyraz "<< word <<" jest palindromem, jest (1- prawda 0-falsz): "<< is_palindrome(word) << std::endl;
    return 0;
}