class CustomStack {
    vector<int> st;
    int maxSize;
public:
    CustomStack(int maxsize) {
        maxSize = maxsize;
    }
    
    void push(int x) {
        if(st.size()<maxSize){
            st.push_back(x);
        }
    }
    
    int pop() {
        int temp = -1;
        if(st.size() > 0){
            temp = st.back();
            st.pop_back();
        }

        return temp;
    }
    
    void increment(int k, int val) {
        int temp = st.size();
        int stackSize = min(k,temp);

        for(int i = 0; i<stackSize; i++){
            st[i] += val;
        }
    }
};