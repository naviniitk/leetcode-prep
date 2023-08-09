// O(nlogn) and O(1)
// Sort the array and return the middle element as the sorted array will always have more than half of the majority element

// O(n) time and O(n) space

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::map<int, int> freq;
        int ans, max_val = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(freq.count(nums[i]) == 0) {
                freq[nums[i]] = 1;
            } else {
                freq[nums[i]]++;
            }
            if ( freq[nums[i]] > max_val) {
                max_val = freq[nums[i]];
                ans = nums[i];
            }
        }
        return ans;
    }
};


// O(n) time ans O(1) space
// Moore Voting Algorithm
// Algorithm:

// Initialize two variables: count and candidate. Set count to 0 and candidate to an arbitrary value.
// Iterate through the array nums:
// a. If count is 0, assign the current element as the new candidate and increment count by 1.
// b. If the current element is the same as the candidate, increment count by 1.
// c. If the current element is different from the candidate, decrement count by 1.
// After the iteration, the candidate variable will hold the majority element.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = 0;
        for(int x:nums) {
            if(count == 0) {
                count++;
                candidate = x;
            } else if (candidate == x) {
                count++;
            } else if (candidate != x) {
                count--;
            }
        }
        return candidate;
    }
};
