class FindSumPairs {
public:
    vector<int> arr1;
    vector<int> arr2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
    }

    void add(int index, int val) { arr2[index] += val; }

    int count(int tot) {
        unordered_map<int, int> mp;

        for (int i = 0; i < arr1.size(); i++) {
            mp[arr1[i]]++;
        }

        int cnt = 0;
        for (int i = 0; i < arr2.size(); i++) {
            int rem = tot - arr2[i];
            if (mp.find(rem) != mp.end()) {
                cnt += mp[rem];
            }
        }

        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */