//
// Created by Kornel on 12.03.2018.
//

#include <iostream>
#include "Xorcypherbreaker.h"
#include <string>
#include <vector>
#include <algorithm>

using std::find;
using std::vector;
using std::string;

int main(){
    //char pass[10] = ;
    vector<char> pass {'c', 'o', 'r', 'n', 'u', 'c', 'o', 'p', 'i', 'a'};
    string passw = "000000";
    string answer;
    answer = XorCypherBreaker(passw, 3);
    std::cout<<answer<<std::endl;
    answer = XorCypherBreaker(answer, 3);
    std::cout<<answer<<std::endl;
}