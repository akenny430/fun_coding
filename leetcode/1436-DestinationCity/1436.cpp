#include <unordered_set>
#include <vector> 
#include <string> 

class Solution {
public:
    std::string destCity(std::vector<std::vector<std::string>>& paths) {
        std::unordered_set<std::string> city_uset; 
        for (const auto& x : paths)
        {
            city_uset.insert(x[0]); 
        }
        for (const auto& x : paths)
        {
            if (city_uset.find(x[1]) == city_uset.end())
            {
                return x[1]; 
            }
        }
        return ""; // need to have this return here 
    }
};