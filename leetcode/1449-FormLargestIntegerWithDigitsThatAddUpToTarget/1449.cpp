#include <array> 
#include <string>
#include <sstream> 
#include <map> 
#include <vector> 

class Solution {
public:
    std::string largestNumber(std::vector<int>& cost, int target) {
        // constructing map of cost to max digit 
        std::map<int, int> cost_mdigit_map; 
        for(int dm1 = 0; dm1 < cost.size(); ++dm1)
        {
            if(
                cost_mdigit_map.find( cost[dm1] ) == cost_mdigit_map.end() // not yet seen 
                || 
                dm1 + 1 > cost_mdigit_map[ cost[dm1] ] // have new larger digit 
            )
            {
                cost_mdigit_map[ cost[dm1] ] = dm1 + 1;
            }
        }

        // constructing costs with bottom-up approach 
        std::array<int, 5001> cost_mlength_array; 
        std::fill(cost_mlength_array.begin(), cost_mlength_array.end(), -1); 
        cost_mlength_array[0] = 0; // set first one to 0 

        std::array<int, 5001> cost_nextCost_array; 
        std::fill(cost_nextCost_array.begin(), cost_nextCost_array.end(), -1); 

        int temp_len; 
        int temp_nextCost; 
        int temp_digit; 
        for(int temp_cost = 1; temp_cost <= target; ++temp_cost)
        {
            temp_len = -1; 
            temp_nextCost = -1; 
            for(const auto& [c_cost, c_digit] : cost_mdigit_map)
            {
                if(
                    temp_cost - c_cost < 0 // not possible index 
                    || 
                    cost_mlength_array[temp_cost - c_cost] == -1 // can't get to previous
                ){ continue; }

                // have larger length, means number will have been larger 
                if( 1 + cost_mlength_array[temp_cost - c_cost] > temp_len )
                {
                    temp_nextCost = c_cost; 
                    temp_len = 1 + cost_mlength_array[temp_cost - c_cost]; 
                    temp_digit = c_digit; 
                }

                // if they are same lengths, have to compare digits to see which to use 
                else if( 1 + cost_mlength_array[temp_cost - c_cost] == temp_len )
                {
                    // be sure to use largest digit 
                    if(c_digit > temp_digit)
                    {
                        temp_nextCost = c_cost; 
                        temp_digit = c_digit; 
                    }
                }
            }
            cost_mlength_array[temp_cost] = temp_len; 
            cost_nextCost_array[temp_cost] = temp_nextCost; 
        }
        
        // if no possible combo, return "0" 
        if(cost_mlength_array[target] == -1){return "0";}

        // extracting proper digits 
        int c_cost = target; 
        std::stringstream results_ss; 
        while(c_cost > 0)
        {
            results_ss << cost_mdigit_map[ cost_nextCost_array[c_cost] ]; 
            c_cost -= cost_nextCost_array[c_cost]; 
        }
        return results_ss.str(); 
    }

};