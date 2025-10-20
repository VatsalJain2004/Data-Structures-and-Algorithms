class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n, 0);
        for(int i = 0; i < n; i++) {
            if(i > 0) {
                prefix[i] = prefix[i-1] + nums[i];
            }
            else {
                prefix[i] = nums[i];
            }
        }
    }
    
    int sumRange(int left, int right) {
        return (left != 0) ? (prefix[right]-prefix[left-1]) : (prefix[right]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */