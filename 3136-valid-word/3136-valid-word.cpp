class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch == 'a' || ch =='e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' )
        {
            return true;
        }else{
            return false;
        }
    }
    bool isNum(char ch)
    {
        if(ch == '1' || ch == '2' || ch == '0' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7'  || ch == '8' || ch == '9')
        {
            return true;
        }else{
            return false;
        }
    }

    bool isValid(string word) {
        
        int n= word.size();

        if(word.size() < 3)
        {
            return 0;
        }

        bool Main = true;
        bool first  = false;
        bool second = false;
        bool third = false;
        
        for(int i =0;i<n;i++)
        {
            if(isNum(word[i]))
            {
                first = true;
            }

            if(isVowel(word[i]))
            {
                second = true;
            }
            if(isalpha(word[i]) && !isVowel(word[i]))
            {
                third = true;
            }

            if(!isalnum(word[i]))
            {
                Main = false;
            }
        }

        bool cond = Main && first && second && third;
        return cond;

    }
};