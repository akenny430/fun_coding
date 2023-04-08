class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        seen_dict = {} 
        for n_index, n_val in enumerate(nums): 
            t_val = target - n_val
            if t_val in seen_dict: # if we have a match 
                return [n_index, seen_dict[t_val]] 
            # add it to the dict 
            seen_dict[n_val] = n_index 
        return [-1]