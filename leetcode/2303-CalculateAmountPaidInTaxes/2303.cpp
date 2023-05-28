#include <vector> 

class Solution {
public:
    double calculateTax(std::vector<std::vector<int>>& brackets, int income) {
        if(income == 0){return 0.0;}
        int paid = 0; 
        int prev_upper = 0; 
        for(const auto& info : brackets)
        { 
            if( info[0] > income )
            { 
                paid += ( income - prev_upper ) * info[1]; 
                break; 
            }
            paid += ( info[0] - prev_upper ) * info[1];
            prev_upper = info[0];  
        }
        // return paid; 
        return static_cast<double>(paid) / 100.0; 
    }
};