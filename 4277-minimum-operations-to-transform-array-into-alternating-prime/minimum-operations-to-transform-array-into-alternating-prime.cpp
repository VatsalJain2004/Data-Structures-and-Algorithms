class Solution {
public:
    int makeItPrime (int num, vector<int>& primeList) {
        int low = 0, high = primeList.size()-1;
        while (low <= high) {
            int mid = (low+high)/2;
            if (primeList[mid] >= num) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return primeList[low] - num;
    }

    bool isPrime(int n) {
        if (n <= 1) return false;
        
        if (n <= 3) return true;
    
        if (n % 2 == 0 || n % 3 == 0) return false;
    
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
    
        return true;
    }

    vector<int> buildPrimeList () {
        vector<int> primeList = {};
        for (int i = 2; i <= 100010; i++) {
            if (isPrime(i)) {
                primeList.push_back(i);
            }
        }
        return primeList;
    }
    
    int minOperations(vector<int>& nums) {
        vector<int> primeList = buildPrimeList();
        int minOperations = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (!isPrime(nums[i])) {
                    minOperations += makeItPrime(nums[i], primeList);
                }
                
            }
            else {
                while (isPrime(nums[i])) {
                    minOperations += 1;
                    nums[i] += 1;
                }
            }
        }
        return minOperations;
    }
};