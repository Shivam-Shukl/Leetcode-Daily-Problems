class Solution {
public:
    int bruteForce(vector<int> &arr)
    {
        int cnt =0;
        int n = arr.size();
        int i =0,j=n-1;
        for(;i<n;i++)
        {
            j = n-1;
            int k = j-1;
            
            for(;j>=i+2;j--)
            {
                k=j-1;
                if(i<k && arr[i] + arr[k] >= arr[j])
                {
                    for(int l = k ;l>i ;l--)
                    {
                        if(arr[l] + arr[i] > arr[j])
                        {
                            
                            cnt++;
                        }
                        else{
                                
                            break;
                        }
                    }
                }
            }
  
        }
        return cnt;
    }
    int triangleNumber(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        return bruteForce(arr);
    }
};