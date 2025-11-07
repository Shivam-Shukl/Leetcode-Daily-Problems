class Solution {
public:
    bool isOpen(char ch){
        return (ch == '(' || ch == '[' || ch == '{');
    }
    bool isCond(char ch1 , char ch2){
        if((ch1 == '(' && ch2 == ')') || (ch1 == '[' && ch2 == ']') || ( ch1 == '{' && ch2 == '}') ){
            return true;
        }else{
            return false;
        }
    }
    bool isValid(string s) {
        stack<int> st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(isOpen(s[i])){
                st.push(s[i]);
            }else{
                if(st.empty()) return false;
                char ch1 = st.top();
                if(isCond(ch1, s[i])){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};