class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) { 
        int he = stoi(endTime.substr(0, 2)), hs = stoi(startTime.substr(0, 2)); 
        int me = stoi(endTime.substr(3, 2)), ms = stoi(startTime.substr(3, 2)); 
        int se = stoi(endTime.substr(6, 2)), ss = stoi(startTime.substr(6, 2)); 

        int ans = 0; 
        ans += (he - hs - 1) * 60 * 60; 
        ans += (60 - ms - 1 + me) * 60; 
        ans += (se + 60 - ss); 

        return ans;      
    }
};