class Solution {
public:
    // int bruteforce(vector<int> & arr)
    // {
    //     int n = arr.size();
    //     int area = 0;
    //     for(int i=0;i<n;i++)
    //     {
    //         int currArea= 0;
    //         int len = arr[i];
    //         int bre =1;
    //         int j = i-1;
    //         while(j>=0 && arr[j] >= arr[i])
    //         {
    //             j--;
    //             bre++;
    //         }
    //         j= i+1;
    //         while(j<n && arr[j] >= arr[i]){
    //             j++;
    //             bre++;
    //         }
    //         currArea = len*bre;
    //         area = max(area,currArea);
    //     }

    //     return area;
    // }

    vector<int> nextSmallerIndex(vector<int> &arr)
    {
        // Write your code here.
         int n = arr.size();
        stack<int> st;
        st.push(-1);
        vector<int> ans(n,-1);
        for(int j=n-1;j>=0;j--)
        {
            int ele = arr[j];
            while(st.top() != -1 && ele <= arr[st.top()])
            {
                st.pop();
            }
            ans[j] = st.top();
            st.push(j);
    
        }
        return ans;
    }

    vector<int> prevSmallerIndex(vector<int> &arr)
    {
        // Write your code here.
         int n = arr.size();
        stack<int> st;
        st.push(-1);
        vector<int> ans(n,-1);
        for(int j=0;j<n;j++)
        {
            int ele = arr[j];
            while(st.top() != -1 && ele <= arr[st.top()])
            {
                st.pop();
            }
            ans[j] = st.top();
            st.push(j);
    
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {

        int n= heights.size();

        vector<int> arr1 =  nextSmallerIndex(heights);
        vector<int> arr2 =  prevSmallerIndex(heights);

        int area = 0;
        for(int i=0;i<n;i++)
        {
            int currArea= 0;
            int len = heights[i];
            int bre =1;
            int next = arr1[i];

            if(next == -1) 
                next = n;
            
            int prev= arr2[i];
            
            
            bre = next - prev -1;
            currArea = len*bre;
            area = max(area,currArea);
        }
      
        return area;
    }
};