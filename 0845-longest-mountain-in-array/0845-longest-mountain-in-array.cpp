class Solution {
public:
    
    int longestMountain(vector<int>& arr) {
        int n = arr.size();

    
        int i =0;
        int ans =0;
        while(i<n)
        {
            
            if(i+1<n && arr[i+1] > arr[i] )
            {
                int cnt =0;
                while(i+1<n && arr[i+1] > arr[i])
                {
                    i++;
                    cnt++;
                   
                }
                if(arr[i+1] < arr[i])
                {
                 
                    while(i+1<n && arr[i+1] <arr[i])
                    {
                        i++;
                        cnt++;
                    }
                    ans = max(cnt,ans);
                }else{
                    cnt=0;
                }
                
            }else{
                i++;
            }
            
        }
        if(ans==0)
        {
            return 0;
        }else{
            return ans+1;
        }

    }
};