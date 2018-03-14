//
// Created by prokkorn on 14.03.18.
//

#include "MinimalTimeDifference.h"
#include <vector>
#include <sstream>
#include <regex>
#include <cmath>

namespace mintimediff{
    using std::string;
    using std::vector;
    unsigned int ToMinutes(string time_HH_MM){
        std::regex pattern {R"(\d{1,2}:\d{2})"};
        std::smatch match;
        if(std::regex_match(time_HH_MM, match, pattern)){
            unsigned int h_1, h_2, m_1, m_2;
            unsigned int result;
            if()
            result = (10*h_1 + h_2)*60 + 10*m_1 + m_2;
        }
    }
    unsigned int MinimalTimeDifference(vector<string> times){
        vector<int> times_new;

    }
}