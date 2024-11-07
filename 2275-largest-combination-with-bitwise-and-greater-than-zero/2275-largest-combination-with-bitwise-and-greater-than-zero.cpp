class Solution {
public: 
    int largestCombination(vector<int>& can) const noexcept {
        vector<uint32_t> INTEGER_(sizeof(int)*8, 0);//define 4 X 8 size olding count of 
        
        //using std::for_each() from algorithm
        std::for_each(can.begin(),can.end(),
            [&INTEGER_](auto &&i){
                
                std::for_each(INTEGER_.begin(),INTEGER_.end(),
                    [&i](auto&& _i){
                        
                        _i += i & 1;
                        i >>= 1;
                    }
                );
            }
        );
        
        return *std::max_element(INTEGER_.begin(),INTEGER_.end());
    }
};