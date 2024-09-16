class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // Convert time string into minutes integer value
        vector<int> minutes;
        for(int i=0; i<timePoints.size(); i++){
            string curr = timePoints[i];

            int hours = stoi(curr.substr(0,2));
            int min = stoi(curr.substr(3,2));
            int totalMinutes = hours*60 + min;
            minutes.push_back(totalMinutes);
        }

        sort(minutes.begin(), minutes.end());

        //Calculate difference and find min.
        int minimum = INT_MAX;
        for(int i=0; i<minutes.size()-1; i++){ 
            int diff = minutes[i+1] - minutes[i];
            minimum = min(minimum, diff);
        }

        int lastDiff = (minutes[0] + 1440) - minutes[minutes.size()-1];
        minimum = min(minimum, lastDiff);
        return minimum;
    }
};