# ✅ Check if a Number is a Sum of Distinct Powers of Three (Ternary-Based Approach)

## Intuition
Any number that can be expressed as a sum of **distinct powers of 3** must have a ternary (base-3) representation consisting of **only digits 0 and 1**.  
If any digit is `2`, it implies using the same power of 3 more than once, which violates the "distinct powers" condition.

## Approach
We repeatedly divide the number `n` by 3 and check the remainder:
- If at any step the remainder is `2`, return `false` since it cannot be represented as a sum of distinct powers of 3.
- If we reach `n == 0` without finding a remainder of `2`, return `true`.

This approach mimics the process of checking whether the **ternary representation** contains only `0` and `1`.

## Complexity
- **Time complexity:** O(log₃ n) — since we divide `n` by 3 in each iteration.
- **Space complexity:** O(1) — no extra space is used.

## Code
```cpp
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n != 0){
            int rem = n % 3;
            if(rem == 2){
                return false;
            }
            n = n / 3;
        }
        return true;
    }
};

```

# ✅ Longest Subarray With Maximum Bitwise AND (LeetCode Style Explanation)

## Intuition
We are given an array and need to find the **length of the longest contiguous subarray** where the **bitwise AND of all elements is equal to the maximum element in the array**.

Initial thought: Since the AND operation only retains `1` bits that are common across all numbers, the **maximum possible AND** in any subarray will be the **maximum number in the array**.  
So, we only need to check which subarrays contain only this max number.

## Approach
1. First, find the **maximum number** in the array, because **no AND can be greater than this**.
2. Traverse the array and count lengths of subarrays made of **only the maximum number**.
3. Keep track of the **maximum such length** encountered.

This works because:
- `max & max = max`
- Any number smaller than max will reduce the AND result

## Complexity
- **Time complexity:** O(n)  
  We traverse the array twice — once to find the maximum, once to find the longest subarray.

- **Space complexity:** O(1)  
  We only use a few variables for tracking.

## Code
```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        int max_no = INT_MIN;

        // Step 1: Find the maximum number
        for (auto x : nums) {
            max_no = max(max_no, x);
        }

        // Step 2: Find the longest contiguous subarray of max_no
        int maxlen = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] == max_no) {
                len += 1;
                maxlen = max(maxlen, len);
            } else {
                len = 0;
            }
        }

        return maxlen;
    }
};
```