class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>min_heap;
        priority_queue<pair<int,char>>max_heap;
        vector<int>v(26,0);
        for(int i=0;i<tasks.size();i++){
            v[tasks[i]-'A']++;
        }
        for(int i=0;i<26;i++){
            if(v[i]!=0)min_heap.push({1,i+'A'});
        }
        int currTime=0;
        while(true){
            if(min_heap.empty() && max_heap.empty())break;
            currTime++;
            while(!min_heap.empty() && min_heap.top().first<=currTime){
                auto [time,alpha]=min_heap.top();
                min_heap.pop();
                if(v[alpha-'A']!=0)max_heap.push({v[alpha-'A'],alpha});
            }
            if(!max_heap.empty()){
                auto[count,alpha]=max_heap.top();
                max_heap.pop();
                v[alpha-'A']--;
                if(v[alpha-'A']!=0)min_heap.push({currTime+n+1,alpha});
                
            }
        }

        return currTime;
    }
};