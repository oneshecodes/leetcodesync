class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        // Create a counts vector of size n+1, initialized to 0.
        // counts[k] will store the number of papers with exactly k citations.
        // counts[n] will store papers with n or more citations.
        vector<int> counts(n + 1, 0);

        // Populate the counts vector
        for (int c : citations) {
            counts[min(c, n)]++; // Increment count for citation c, capping at n
        }

        int total_papers = 0;
        // Iterate backwards from the maximum possible h-index (n) down to 0
        for (int i = n; i >= 0; --i) {
            // Add the number of papers with exactly i citations (or >=n if i==n)
            total_papers += counts[i]; 
            
            // Check if we have found 'i' papers with at least 'i' citations
            if (total_papers >= i) {
                // Since we are iterating downwards, this 'i' is the highest possible value
                // satisfying the h-index definition.
                return i;
            }
        }

        // Should not be reached if n > 0, but covers edge cases.
        return 0; 
    }
};
        