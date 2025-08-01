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

# 🧠 Intuition

The problem is to generate the first `numRows` of **Pascal's Triangle**.  
The key observation is that:
- The first and last elements of each row are always `1`.
- The inner elements are the **sum of two elements directly above it** from the previous row.

---

# 🛠️ Approach

1. Initialize an empty 2D vector `ans` to store all rows.
2. For each row `i` (0-indexed):
   - Create a vector `nums` of size `i + 1` initialized with `0`.
   - Set the first element `nums[0] = 1`.
   - For each inner index `j` (from 1 to `i-1`), compute:
     ```
     nums[j] = ans[i-1][j-1] + ans[i-1][j];
     ```
   - If `i != 0`, set `nums[i] = 1` (last element of the row).
   - Push `nums` into `ans`.

---

# ⏱️ Complexity

- **Time Complexity:**  
  $$O(n^2)$$  
  Because we compute every element in the triangle up to `numRows`.

- **Space Complexity:**  
  $$O(n^2)$$  
  We store the entire triangle, which consists of about \( \frac{n(n+1)}{2} \) elements.

---

# 💻 Code

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            vector<int> nums(i + 1, 0);
            nums[0] = 1;
            for (int j = 1; j < i; j++) {
                nums[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            if (i != 0) nums[i] = 1;
            ans.push_back(nums);
        }
        return ans;
    }
};
```

# 898. Bitwise ORs of Subarrays

## 🔍 Intuition
To find the number of **distinct bitwise OR results** from all **non-empty subarrays**, we can take advantage of a key property of bitwise OR:
- **Monotonic behavior**: Once a bit is set in an OR operation, it remains set for subsequent ORs.
- So, we can build the OR values of subarrays incrementally using previously computed results, avoiding redundant computations.

---

## 🧠 Approach
1. Use a set `res` to store all **unique OR results** across subarrays.
2. Maintain a set `cur` that keeps track of **OR values of subarrays ending at the current index**.
3. For each number `num` in the array:
   - Create a new set `new_cur` initialized with `{num}`.
   - For each value `val` in `cur`, compute `val | num` and insert into `new_cur`.
   - Replace `cur` with `new_cur`.
   - Insert all values from `cur` into `res`.

This way, each new element extends the subarrays and updates the possible OR results efficiently.

---

## ⏱️ Complexity

- **Time Complexity:**  
  \( O(N \cdot \log M) \)  
  Where:
  - \( N \) is the length of the array.
  - \( M \) is the max OR value possible (bounded by 32 bits since \( arr[i] \leq 10^9 \)).

- **Space Complexity:**  
  \( O(M) \)  
  For the result and intermediate sets, limited by number of distinct OR results (at most 32 in practice for 32-bit integers).

---

## ✅ Code (C++)
```cpp
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, cur;
        for (int num : arr) {
            unordered_set<int> new_cur = {num};
            for (int val : cur) {
                new_cur.insert(val | num);
            }
            cur = move(new_cur);
            res.insert(cur.begin(), cur.end());
        }
        return res.size();
    }
};
```