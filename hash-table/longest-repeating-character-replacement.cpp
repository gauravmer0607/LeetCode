class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxele = 0;
        int maxlen = 0;
        int left = 0;
        unordered_map<char,int> mpp;
        for (int right = 0; right < n; right++) {
            mpp[s[right]]++;
            maxele = max(maxele, mpp[s[right]]);
            while ((right - left + 1) - maxele > k) {
                mpp[s[left]]--;
                left++;
            }
            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};