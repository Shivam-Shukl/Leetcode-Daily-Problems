class Solution {
public:
    int convert(string s) {
        long long no = 0;
        long long mul = 1;
        for (int j = s.size() - 1; j >= 0; j--) {
            no += mul * (s[j] - '0');
            mul = mul * 2;
        }
        return no;
    }

    string help(int n, int size) {
        string s;
        while (n) {
            int rem = n % 2;
            s.push_back((rem + '0'));
            n = n / 2;
        }
        reverse(s.begin(), s.end());
        while (s.size() != size) {
            s = '0' + s;
        }
        return s;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int val = 0;
        string ans = "";
        for (int i = 0; i < nums.size(); i++) {
            int temp = convert(nums[i]);

            if (val != temp) {
                ans = help(val, n);

                break;
            }
            val += 1;
        }
        if (ans.size() == 0) {
            ans = help(val, n);
        }

        return ans;
    }
};