class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            pq.push(nums[i]);
        }
        while (!pq.empty() && k > 1) {
            pq.pop();
            k--;
        }
        if (pq.empty())
            return -1;
        return pq.top();
    }
};