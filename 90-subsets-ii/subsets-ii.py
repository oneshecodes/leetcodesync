class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = [[]]
        start = end = 0
        for i in range (len(nums)):
            start =0
            if i > 0 and nums [i] == nums[i- 1]:
                start = end +1
            end = len(res) -1
            for j in range (start, len(res)):
                res.append(res[j]+ [nums[i]])
        return res        