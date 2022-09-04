// link: https://leetcode.com/problems/my-calendar-i/

class MyCalendar {
    vector<pair<int,int>> calender;
public:
    MyCalendar() {
        calender.clear();
    }
    
    bool book(int start, int end) {
        for(auto &x:calender){
            if(!(end<=x.first||start>=x.second)) return false;
        }
        calender.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */