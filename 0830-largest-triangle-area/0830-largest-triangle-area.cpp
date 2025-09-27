class Solution {
public:
    double dist(int x1, int y1, int x2, int y2){
        double ans  = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
        return ans;
    }
    double heronsf(double x, double y ,double z){
        double s = (x + y + z)/2.0;
        double ans = sqrt(s*(s-x)*(s-y)*(s-z));
        return ans;
    }
    double largestTriangleArea(vector<vector<int>>& points) {

        double maxi = 0;
        int n = points.size();
        for(int i=0;i<n-2;i++){
            int x1=points[i][0],y1 = points[i][1];
            for(int j= i+1;j<n-1;j++){
                int x2 = points[j][0], y2 = points[j][1];
                for(int k = j+1;k<n;k++){
                    int x3 = points[k][0], y3 = points[k][1];
                    double x = dist(x1,y1,x2,y2);
                    double y = dist(x1,y1, x3,y3);
                    double z = dist(x2,y2,x3,y3);
                    double area = heronsf(x,y,z);
                    if(maxi < area){ 
                        maxi= area;
                    }
                }
            }
        }
        return maxi;
    }
};