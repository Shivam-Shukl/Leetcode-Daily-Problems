class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int v[5] = {0,0,0,0,0};
        int n = text.size();
        for(int i =0;i<n;i++){
            if(text[i] == 'a'){
                v[0]++;
            }else if(text[i] == 'b'){
                v[1]++;
            }else if(text[i] == 'l'){
                v[2]++;
            }else if(text[i] == 'o'){
                v[3]++;
            }else if(text[i] == 'n'){
                v[4]++;
            }else{
                continue;
            }
        }
        v[3] = v[3]/2;
        v[2] = v[2]/2;
        int mini = INT_MAX;
        for(int i =0;i<5;i++){
            mini = min(mini,v[i]);
        }
        return mini;
    }
};