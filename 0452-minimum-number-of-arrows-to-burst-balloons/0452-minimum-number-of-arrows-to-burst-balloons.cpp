class Solution {
        static bool comp(vector<int>&a, vector<int>&b){
        return a[1] < b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        //sort on the basis of x.end
        sort(points.begin(),points.end(),comp);
        int arrows=1; //we need 1 arrow for the first balloon for sure
        int end=points[0][1];
        int temp = 0;
        for(int i=1;i<points.size();i++){
            //comparing the xi.end with xi+1.start 
            if(points[i][0] > end){
                arrows++;
                temp++;
                end=points[i][1];
            }
        }
        return arrows;
    }
};