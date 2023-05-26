/* https://leetcode.com/problems/kth-largest-element-in-a-stream/
703. Kth Largest Element in a Stream
Easy
Heap
*/
class KthLargest {
private:
    int req;
    priority_queue<int,vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        req = k;
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        if (minHeap.size() < req) {
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};