/* https://leetcode.com/problems/snapshot-array
1146. Snapshot Array
Medium
Binary Search Map
*/
class SnapshotArray {
public:
    vector<map<int,int>> mMap;
    int s=0;
    SnapshotArray(int length) {
        mMap.resize(length);
        for(int i =0;i<length;i++){
            mMap[i][0] = 0;
        }
    }
    
    void set(int index, int val) {
        mMap[index][s] = val;
    }
    
    int snap() {
        s++;
        return s-1;
    }
    
    int get(int index, int snap_id) {
        if(!mMap[index].count(snap_id)){
            auto i = --mMap[index].lower_bound(snap_id);
            return i->second;
        }
        return mMap[index][snap_id];
    }
};
