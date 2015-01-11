#include <iostream>
#include <map>
std::string  longest_non_repeating_string(std::string s) {
    // Maitain a map of character to identify what
    // characters are present in LNRS
    std::map<char, int>  LNRS;
    int maxLen = -1;
    int currLen = 0;
    std::string currString  = "";
    std::string maxString   = ""; 
    for (auto& c : s) {
        if (LNRS.find(c) == LNRS.end()) {
            currLen += 1;
            LNRS[c] = 1;
            currString.push_back(c);
            if (currString.length() > maxString.length()) {
                maxLen = currLen;
                maxString = currString;
            }
        } else {
            // Index of repeated char in the current String
            int repIndex = currString.find(c);
            for (auto i = 0; i < repIndex; i++) {
               LNRS.erase(currString[i]);
            }
            currString.erase(0, repIndex+1);
            currString.push_back(c);

        }
        std::cout << "-------------------------------" << std::endl;
        std::cout << "Curr String " << currString << std::endl;
        std::cout << "Curr Char  " << c << std::endl;
        std::cout << "Max String " << maxString << std::endl;
        std::cout << "------------------------------------ " << std::endl;
    }

    //for (auto& kv : LNRS) {
    //    std::cout << kv.first << " " << kv.second << std::endl;
    // }
    return maxString;
}

int main() {
    //std::cout << longest_non_repeating_string("aabacd") << std::endl;
    std::cout << longest_non_repeating_string("ABDEFGABEF") << std::endl;

    return 0;
}
