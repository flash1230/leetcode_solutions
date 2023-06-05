/* https://leetcode.com/problems/design-hashset
705. Design HashSet
Easy
*/
class MyHashSet {
public:
    bool mp[1000002]={false};
    MyHashSet() {
        
    }
    
    void add(int key) {
        mp[key] = true;
    }
    
    void remove(int key) {
        mp[key] = false;
    }
    
    bool contains(int key) {
        return mp[key];
    }
};