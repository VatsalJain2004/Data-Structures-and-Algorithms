class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int maxVolume = 0;
        while(i <= j) {
            int a = height[i], b = height[j];
            int volume = min(a, b) * (j-i);
            maxVolume = max(maxVolume, volume);
            if(a > b) {
                j -= 1;
            }
            else {
                i += 1;
            }
        }
        return maxVolume;
    }
};