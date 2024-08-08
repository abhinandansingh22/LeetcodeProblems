class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c) {
        int right = 1, left = 2, down = 1, up = 2;

        vector<vector<int>> v;
        vector<int> temp = {r,c};
        v.push_back(temp);
        int visited = 1;
        int cur_i = r, cur_j = c;
        while(visited < rows*cols) {
            if(cur_i >= 0) {
                for(int i=1;i<=right;i++) {
                    cur_j++;
                    if(cur_j < cols && cur_j >= 0 && cur_i < rows && cur_i >= 0) {
                        temp = {cur_i,cur_j};
                        v.push_back(temp);
                        visited++;
                    }
                }
            }
            else{
                for(int i=1;i<=right;i++) {
                    cur_j++;
                }
            }

            right = left+1;


            if(cur_j < cols) {
                for(int i=1;i<=down;i++) {
                    cur_i++;
                    if(cur_j < cols && cur_j >= 0 && cur_i < rows && cur_i >= 0) {
                        temp = {cur_i,cur_j};
                        v.push_back(temp);
                        visited++;
                    }
                }
            }
            else{
                for(int i=1;i<=down;i++) {
                    cur_i++;
                }
            }

            down = up+1;

            if(cur_i < rows) {
                for(int i=1;i<=left;i++) {
                    cur_j--;
                    if(cur_j < cols && cur_j >= 0 && cur_i < rows && cur_i >= 0) {
                        temp = {cur_i,cur_j};
                        v.push_back(temp);
                        visited++;
                    }
                }
            }
            else{
                for(int i=1;i<=left;i++) {
                    cur_j--;
                }
            }

            left = right+1;

            if(cur_j >= 0) {
                for(int i=1;i<=up;i++) {
                    cur_i--;
                    if(cur_j < cols && cur_j >= 0 && cur_i < rows && cur_i >= 0) {
                        temp = {cur_i,cur_j};
                        v.push_back(temp);
                        visited++;
                    }
                }
            }
            else{
                for(int i=1;i<=up;i++) {
                    cur_i--;
                }
            }

            up = down+1;
        }

        return v;
    }
};