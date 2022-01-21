// Link to the problem
// https://leetcode.com/problems/reverse-pairs/

class Solution {
public:
int helper2(vector < int > & nums, int low, int mid, int high) {
  int total = 0;
  int j = mid + 1;
  for (int i = low; i <= mid; i++) {
    while (j <= high && nums[i] > 2 *(long)nums[j]) {
      j++;
    }
    total += (j - (mid + 1));
  }

  vector < int > t;
  int left = low, right = mid + 1;

  while (left <= mid && right <= high) {

    if (nums[left] <= nums[right]) {
      t.push_back(nums[left++]);
    } else {
      t.push_back(nums[right++]);
    }
  }

  while (left <= mid) {
    t.push_back(nums[left++]);
  }
  while (right <= high) {
    t.push_back(nums[right++]);
  }

  for (int i = low; i <= high; i++) {
    nums[i] = t[i - low];
  }
  return total;
}
    int helper(vector<int> &nums, int l, int r){
        int ans=0;
        if(l<r){
            int m = (l+r)/2;
            ans+=(helper(nums,l,m));
            ans+=(helper(nums,m+1,r));
            ans+=helper2(nums,l,m,r);
        }
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        int ans=helper(nums,0,nums.size()-1);
        return ans;
    }
};