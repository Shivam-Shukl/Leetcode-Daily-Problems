class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int n = mat.size();
        vector<int> ans;
        vector<int> temp1(n,0);
        priority_queue<pair<int,int>> pq;

        for(int i=0;i<n;i++)
        {
            int cnt =0;
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j] == 1)
                {
                    cnt++;
                }
            }
            temp1[i] = cnt;
        }

        for(int i =0;i<temp1.size();i++)
        {
            int cnt = 0;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                else{
                    if(temp1[i] == temp1[j] && j>i)
                    {
                        cnt++;
                    }else if(temp1[i] < temp1[j])
                    {
                        cnt++;
                    }

                }
            }
            pq.push({cnt,i});
        }

        for(int i=0;i<k;i++)
        {
            pair<int,int>p = pq.top();
            pq.pop();
            int ele = p.second;
            ans.push_back(ele);
        }
        return ans;
        
    }
};