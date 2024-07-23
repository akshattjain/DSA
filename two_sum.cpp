class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map <int, int > mpp;
        int n=nums.size();
        int extra=0;
        for(int i=0;i<n;i++)
        {

            extra=target-nums[i];

            if(mpp.find(extra) != mpp.end())
            {
                return {mpp[extra],i};
            }

            mpp[nums[i]]=i;
        }

        return {-1,-1};
    }
};