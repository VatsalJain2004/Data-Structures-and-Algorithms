class Solution {
public:
    inline static vector<int> sequentialNumbers = [] {
        vector<int> numbers;
        numbers.reserve(45);

        for (int i = 1; i < 10; i++) {
            numbers.push_back(i);
        }

        for (int i = 0; i < numbers.size(); i++) {
            int nextNum = (numbers[i] % 10) + 1;
            if (nextNum - 1 < 9) {
                numbers.push_back(numbers[i]*10 + nextNum);
            }
        }

        return numbers;
    }();        

    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        for (int& num: sequentialNumbers) {
            if (num >= low && num <= high) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};