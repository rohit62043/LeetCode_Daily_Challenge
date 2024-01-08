// 446. Arithmetic Slices II - Subsequence

int recSolve(vector<int> &nums, int index, int prev, long long diff, int count)
{
    if (index == nums.size())
    {
        if (count >= 3)
        {
            return 1;
        }
        return 0;
    }

    // include
    int include = 0;
    // first element
    if (prev == -1 && diff == INT_MIN)
    {
        include = recSolve(nums, index + 1, index, diff, count + 1);
    }
    // second element
    if (prev != -1 && diff == INT_MIN)
    {
        include = recSolve(nums, index + 1, index, ((long long)nums[index] - nums[prev]), count + 1);
    }

    if (prev != -1 && ((long long)nums[index] - nums[prev]) == diff)
    {
        include = recSolve(nums, index + 1, index, diff, count + 1);
    }

    // exclude
    int exclude = recSolve(nums, index + 1, prev, diff, count);

    return (include + exclude);
}
int memoSolve(vector<int> &nums, int index, int prev, long long diff, int count, unordered_map<string, int> &dp)
{
    if (index == nums.size())
    {
        if (count >= 3)
        {
            return 1;
        }
        return 0;
    }

    string key = to_string(index) + "_" + to_string(prev) + "_" + to_string(diff) + "_" + to_string(count);
    if (dp.find(key) != dp.end())
    {
        return dp[key];
    }

    // include
    int include = 0;
    // first element
    if (prev == -1 && diff == INT_MIN)
    {
        include = memoSolve(nums, index + 1, index, diff, count + 1, dp);
    }
    // second element
    if (prev != -1 && diff == INT_MIN)
    {
        include = memoSolve(nums, index + 1, index, ((long long)nums[index] - nums[prev]), count + 1, dp);
    }

    if (prev != -1 && ((long long)nums[index] - nums[prev]) == diff)
    {
        include = memoSolve(nums, index + 1, index, diff, count + 1, dp);
    }

    // exclude
    int exclude = memoSolve(nums, index + 1, prev, diff, count, dp);

    return dp[key] = (include + exclude);
}

int tabular(vector<int> &nums)
{
    unordered_map<long, int> dp[nums.size()];

    int count = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            long diff = (long)nums[i] - nums[j];
            auto it = dp[j].find(diff);
            int curr_count = it != dp[j].end() ? it->second : 0;
            count += curr_count;
            dp[i][diff] += curr_count + 1;
        }
    }
    return count;
}

int numberOfArithmeticSlices(vector<int> &nums)
{
    //    return recSolve(nums,0,-1,INT_MIN,0);
    //    unordered_map<string,int> dp;
    //    return memoSolve(nums,0,-1,INT_MIN,0,dp);
    return tabular(nums);
}