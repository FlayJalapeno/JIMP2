//
// Created by Kornel on 12.03.2018.
//

#include "XorCypherBreaker.h"
#include <string>
#include <vector>
#include <algorithm>

using std::find;
using std::vector;
using std::string;
/*
string XorCypherBreaker(vector<string> &cryptogram, int key_length, vector<string> &dictionary) {
    char key[3] = {'0', '0', '0'};
    string answer = "";
    int i, j;
    bool done = false;
    while(!done){
                answer = "";
                for (i=0; i<cryptogram.size(); i++){
                    j = i % key_length;
                    answer += (char(cryptogram[i]) ^ key[j]);
                }
                if (find(dictionary.begin(), dictionary.end(), answer) != dictionary.end()) done = true;
                else if (key[2] != 122) key[2] = key[2] + 1;
                else if (key[1] != 122) key[1] = key[1] + 1;
                else if (key[0] != 122) key[0] = key[0] + 1;
        }
    return answer;
}
*/
string XorCypherBreaker(const vector<char> &cryptogram, int key_length, const vector<std::string> &dictionary){
    string key_guess, key_match;
    vector<string> tekst;             //lista slow ktore porownoje ze slownikiem
    tekst.emplace_back("");
    bool done = false;
    int it = 0, it_t = 0, match = 0, match_max = 0;
    char lit;
    key_guess = "aaa";
    while(!done){                                                   //robi dopoki nie dojdzie do "zzz"
        lit = (char)(cryptogram[it] ^ key_guess[it%3]);             //xoruje
        if((lit >= 'a' && lit <= 'z' ) || (lit >= 'A' && lit <= 'Z')){
            tekst[it_t].push_back(lit);                     //jak odszyfrowany znak jest litera to dodaje do ostatniego slowa na liscie
        }else{
            if(lit == ' '){
                tekst.emplace_back("");                             //jak jest spacja to tworzy nowe slowo
                it_t++;
            }
        }
        it++;
        if(it == cryptogram.size()){                        //po odszyfrowaniu wszystkiego
            while(!tekst.empty()){
                if(dictionary.end() != find(dictionary.begin() , dictionary.end() , tekst.back())){
                    match++;                                //szukam i licze slowa ktore sa w slowniku
                }
                tekst.pop_back();
            }
            if(match > match_max){
                key_match = key_guess;              //sprawdzam ktory klucz ma najwiecej dopasowanych slow, zapamietuje go
                match_max = match;
            }
            match = 0;
            if(key_guess[2] == 'z'){                //zmieniam klucz na nastepny
                if(key_guess[1] == 'z'){
                    if(key_guess[0] == 'z'){
                        done = true;
                    }else{
                        key_guess[0] = (char)((int)key_guess[0] + 1);
                    }
                    key_guess[1] = 'a';
                }else{
                    key_guess[1] = (char)((int)key_guess[1] + 1);
                }
                key_guess[2] = 'a';
            }else{
                key_guess[2] = (char)((int)key_guess[2] + 1);
            }
            it = 0;
            tekst.clear();                          //reset wszystkich potrzebnych wartosci
            it_t = 0;
            tekst.emplace_back("");
        }
    }
    return key_match;           //zwracam najlepiej dopasowany klucz
}