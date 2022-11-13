#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen_map; 
        int curr_val, temp_val; 
        for (int curr_index = 0; curr_index < nums.size(); ++curr_index)
        {
            curr_val = nums[curr_index]; 
            temp_val = target - curr_val; 
            if (seen_map.find(temp_val) != seen_map.end()) /* If temp_val is in the map, return it */
                return {curr_index, seen_map[temp_val]}; 
            seen_map[curr_val] = curr_index; /* Add it to map */
        }
        return {}; 
    }
};

/**
 * COMMENTS 
 * 
 * Fastest way is to store values into a map 
 * For the nums vector, we move through each curr_index and curr_value 
 * Idea is to have tracked the values that we have already seen 
 * So for each one, look at target - curr_val 
 * If we have seen this value before, then we are done 
 * 
 * So the seen_map is an unordered_map 
 * They keys are the value of nums vector 
 * The values are the index of nums vector 
*/