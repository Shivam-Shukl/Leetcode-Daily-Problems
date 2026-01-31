class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int val = target - 'a';

        for (char c : letters) {
            if (c - 'a' > val) {
                return c;
            }
        }

        return letters[0];
    }
};
