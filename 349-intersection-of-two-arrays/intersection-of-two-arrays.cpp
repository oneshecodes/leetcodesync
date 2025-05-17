#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashSet(nums1.begin(), nums1.end()); // Store unique elements of nums1
        unordered_set<int> result;  // To store intersection

        // Check elements of nums2 in hashSet
        for (int num : nums2) {
            if (hashSet.count(num)) {
                result.insert(num); // Store only unique intersecting elements
            }
        }

        // Convert result set to vector and return
        return vector<int>(result.begin(), result.end());
    }
};
