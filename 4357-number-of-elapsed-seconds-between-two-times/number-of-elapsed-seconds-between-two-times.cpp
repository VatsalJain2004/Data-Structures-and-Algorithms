class Solution {
public:
    int toSeconds (string& time) {
        return stoi(time.substr(0, 2)) * 3600 + stoi(time.substr(3, 5)) * 60 + stoi(time.substr(6, time.length()));
    }

    int secondsBetweenTimes(string startTime, string endTime) { 
        int startSec = toSeconds(startTime), endSec = toSeconds(endTime);
        return endSec - startSec;      
    }
};