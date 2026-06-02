class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int cuurentTime = 0;
        int maxi = INT_MAX;
        int n = landStartTime.size(), m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            int time = landStartTime[i] + landDuration[i];
            
            for (int j = 0; j < m; j++) {
                int value = 0;
                if(waterStartTime[j] <= time){
                    value = time + waterDuration[j];
                }else{
                    value = waterStartTime[j] + waterDuration[j];
                }
                maxi = min(maxi , value);
            }
        }

        cout << endl;

        for (int i = 0; i < m; i++) {
            int time = waterStartTime[i] + waterDuration[i];
         
            for (int j = 0; j < n; j++) {
                int value = 0;
                if(landStartTime[j] <= time){
                    value = time + landDuration[j];
                }else{
                    value = landStartTime[j] + landDuration[j];
                }
                maxi = min(maxi , value);
            }
        }

        return maxi;
    }
};