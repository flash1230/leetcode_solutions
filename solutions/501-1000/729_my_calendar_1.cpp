/* https://leetcode.com/problems/my-calendar-i/
729. My Calendar I
Medium
*/
class MyCalendar {
public:
    vector<pair<int, int>> slots;
    MyCalendar() {
        
    }
    bool Search(int num1, int num2)
    {
        for(int m = 0; m<slots.size(); m++)
        {
            if(num1 < slots[m].second && slots[m].first<num2)
                return true;
        }
        return false;
    }
    bool book(int start, int end) {
        if(!Search(start, end))
        {
            slots.push_back({start, end});
            return true;
        }
        return false;
    }

};