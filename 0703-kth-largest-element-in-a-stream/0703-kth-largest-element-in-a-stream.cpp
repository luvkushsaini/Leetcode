class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>min_heap;
    priority_queue<int>max_heap;
    int pos;
    KthLargest(int k, vector<int>& nums) {
        pos=k;
        for(int i=0;i<nums.size();i++){
            if(min_heap.size()<k)min_heap.push(nums[i]);
            else {
                if(nums[i]<min_heap.top())max_heap.push(nums[i]);
                else {
                     min_heap.push(nums[i]);
                     max_heap.push(min_heap.top());
                     min_heap.pop();
                }
            }
        }

    }
    
    int add(int val) {
         if(min_heap.size()<pos)min_heap.push(val);
            else {
                if(val<min_heap.top())max_heap.push(val);
                else {
                     min_heap.push(val);
                     max_heap.push(min_heap.top());
                     min_heap.pop();
                }
            }

            return min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */