class Solution {
public:
    string addOne(string s, int i) {
        string res = s.substr(0, i + 1);
        int j = res.size() - 1;
        
        while (j >= 0 && res[j] == '1') {
            res[j] = '0';
            j--;
        }
        
        if (j == -1) {
            res = '1' + res;
        } else {
            res[j] = '1';
        }
        return res;
    }

    int numSteps(string s) {
        int step = 0;
        
        while (s != "1") {
            step++;
            if (s.back() == '0') {
                s.pop_back();
            } else {
                s = addOne(s, s.size() - 1);
            }
        }
     
        return step;
    }
};