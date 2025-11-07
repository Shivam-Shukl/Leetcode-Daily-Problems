class Solution {
public:
    bool isValid(string s) {

        stack <char> Sta;
        int n = s.length();

        for(int i=0 ;i<n;i++)
        {
            char C= s[i];

            // if opening bracket than push in the stack 

            if(C =='(' || C =='{' || C =='[')
            {
                Sta.push(C);
            }
            // if closing bracket than check and pop 
            else
            {
                if(!Sta.empty())
                {
                    char top = Sta.top();
                    if( (C==')' && top == '(') || ( C=='}' && top == '{') || (C==']' && top == '[') )
                    {
                        Sta.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }

        }
        if(Sta.empty())
        return true;
        else 
        return false;
        
    }
};