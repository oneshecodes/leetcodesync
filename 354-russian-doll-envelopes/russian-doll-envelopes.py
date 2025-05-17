class Solution(object):
    def maxEnvelopes(self, envelopes):
        # Sort envelopes by width in ascending order.
        # If two envelopes have the same width, sort by height in descending order.
        envelopes.sort(key=lambda x: (x[0], -x[1]))

        # Extract the heights into a separate list.
        heights = [envelope[1] for envelope in envelopes]

        # The 'ans' list will store the increasing subsequence of heights.
        ans = []

        for height in heights:
            # Find the position where 'height' can be placed in 'ans' using binary search.
            pos = bisect_left(ans, height)

            # If 'height' is greater than all elements in 'ans', append it.
            if pos == len(ans):
                ans.append(height)
            # Otherwise, replace the element at the found position with 'height'.
            else:
                ans[pos] = height

        # The size of 'ans' represents the length of the longest increasing subsequence.
        return len(ans)