class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;
        
        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }

        int majorityElem = nums[0];
        for(auto& p: freq){
            int count = p.second;
            if(count > n/2){
                majorityElem = p.first;
            }
        }
        return majorityElem;
    }
};