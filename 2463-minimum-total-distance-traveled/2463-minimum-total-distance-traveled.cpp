class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> fp;
        for(auto& f: factory){
            for(int i = 0; i < f[1]; i++){
                fp.push_back(f[0]);
            }
        }

        int rc = robot.size(), fc = fp.size();
        vector<long long> next(fc + 1, 0);
        vector<long long> current(fc + 1, 0);

        for(int i = rc - 1; i >= 0; i--){
            if(i != rc - 1) next[fc] = 1e12;

            current[fc] = 1e12;

            for(int j  = fc - 1; j >= 0; j--){
                long long assign = abs(robot[i] - fp[j]) + next[j + 1];

                long long skip = current[j + 1];

                current[j] = min(assign, skip);
            }

            next = current;
        }

        return current[0];
    }
};