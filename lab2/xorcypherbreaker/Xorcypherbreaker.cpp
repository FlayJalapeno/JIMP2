//
// Created by Kornel on 12.03.2018.
//

#include "Xorcypherbreaker.h"
#include <string>
#include <vector>
#include <algorithm>

using std::find;
using std::vector;
using std::string;

string XorCypherBreaker(vector<string> &cryptogram, int key_length, vector<string> &dictionary) {
    char key[3] = {'0', '0', '0'};
    string answer = "";
    int i, j;
    bool done = false;
    while(!done){
                answer = "";
                for (i=0; i<cryptogram.size(); i++){
                    j = i % key_length;
                    answer += (cryptogram[i] ^ key[j]);
                }
                if (find(dictionary.begin(), dictionary.end(), answer) != dictionary.end()) done = true;
                else if (key[2] != 122) key[2] = key[2] + 1;
                else if (key[1] != 122) key[1] = key[1] + 1;
                else if (key[0] != 122) key[0] = key[0] + 1;
        }
    return answer;
}