#include <vector>

class Solution {
public:
    bool isPalindrome(int x) {
        // negative will always be false
        if(x < 0) { return false; }

        // going to store individual digits into vector and check that way
        std::vector<int> number_digits{ };
        int curr_val{ x };
        int digit{ };
        while(true)
        {   
            // computing digit
            digit = curr_val % 10;
            curr_val = (curr_val - digit) / 10;
            number_digits.push_back(digit);
            // this will be 0 once we hit last digit
            if(curr_val == 0) {break;}
        }

        // now checking for palindrome
        std::size_t i{ 0 };
        std::size_t j{ number_digits.size() - 1 };
        while(i < j)
        {
            if(number_digits.at(i) != number_digits.at(j)) {return false;}
            ++i;
            --j;
        }
        return true;
    }
};