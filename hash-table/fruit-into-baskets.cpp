class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxlen = INT_MIN;
        unordered_map<int, int> mpp;
        int left = 0, right = 0;
        int n = fruits.size();
        while (right < n) {
            mpp[fruits[right]]++;
            while (left <= right && mpp.size() > 2) {
                mpp[fruits[left]]--;
                if (mpp[fruits[left]] == 0) {
                    mpp.erase(fruits[left]);
                }
                left++;
            }
            maxlen = max(maxlen, right - left + 1);
            right++;
        }
        return maxlen;
    }
};