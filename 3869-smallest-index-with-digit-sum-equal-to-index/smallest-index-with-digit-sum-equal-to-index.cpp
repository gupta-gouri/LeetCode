class Solution {
public:
    int sum_of_digits(int num){
        int sum = 0;
        while(num > 0){
            int lastdigit = num % 10;
            sum += lastdigit;
            num /= 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(sum_of_digits(nums[i]) == i) return i;
        }
        return -1;
    }
};