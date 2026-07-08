class MedianFinder {
public:
    priority_queue<int ,vector<int>,greater<int>>min_heap;
    priority_queue<int>max_heap;
    MedianFinder() {
        
    }
    void addNum(int num) {
        if(!max_heap.empty() && max_heap.top()<num)min_heap.push(num);
        else max_heap.push(num);
        if(max_heap.size()<min_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        else if((min_heap.size()+1)<max_heap.size()){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }
    
    double findMedian() {
        if(min_heap.size()<max_heap.size()){
            return (double)max_heap.top();
        }
        else{
            double ans=(max_heap.top()+min_heap.top())/2.0;
            return ans;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */