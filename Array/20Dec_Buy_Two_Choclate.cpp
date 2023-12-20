class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int first=prices[0];
        int second=prices[1];

        if(first+second<=money){
            return money-(first+second);
        }

        return
    }
};