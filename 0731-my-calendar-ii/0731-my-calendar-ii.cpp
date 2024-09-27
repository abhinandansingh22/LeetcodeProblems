class MyCalendarTwo {
    // segment tree: log N -> index exceed range
    map<int, int> events;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        events[start] = events[start];

        int count = 0, ans = -1;   
        for( auto& e : events ){
            // must stop by start
            count += e.second;
            if( start <= e.first && e.first < end )
                ans = max(ans, count);
        }
        

        if( ans < 2 ){
            events[start]++;
            events[end]--;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */