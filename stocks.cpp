class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int maxi=0;
        int mini=prices[0];
        int profit=0;

        for (int i=0;i<prices.size();i++)
        {
            profit=prices[i]-mini;

            maxi=max(maxi,profit);

            mini=min(mini,prices[i]);
        }
        return maxi;
    }
};