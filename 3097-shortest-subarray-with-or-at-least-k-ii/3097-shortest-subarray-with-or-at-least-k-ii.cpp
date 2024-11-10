#define isBit1(x, i) ((x >> i) & 1)
class Solution {
public:
    inline int setBit1(int x, int i) {
        return (x | (1 << i));
    }
    
    inline int setBit0(int x, int i) {
        return (x & ~(1 << i));  
    }

    int minimumSubarrayLength(vector<int>& n, int k) {
        vector<int> v(32, 0);
        int or_val = 0;
        int l = 0, len = INT_MAX;
        
        for (int i = 0; i < n.size(); i++) {
            or_val = or_val | n[i];
            for (int j = 0; j < 32; j++) {
                if (isBit1(n[i], j) == 1) v[j]++;
            }

            while (or_val >= k && l <= i) {  // Fix: change l < i to l <= i
                len = min(len, i - l + 1);   // Fix: use i - l + 1 for length
                for (int j = 0; j < 32; j++) {
                    if (isBit1(n[l], j) == 1) {
                        if (v[j] == 1) {
                            or_val = setBit0(or_val, j);
                        }
                        v[j]--;
                    }
                }
                l++;
            }
        }
        
        return len == INT_MAX ? -1 : len;
    }
};
