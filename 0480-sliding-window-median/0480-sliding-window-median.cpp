class Solution {
public:
    multiset<int> mn;
    multiset<int,greater<int>> mx;
    int size;

    void balance(){
        while(mx.size()>size){
            mn.insert(*mx.begin());
            mx.erase(mx.begin());
        }

        while(mx.size()<size&&!mn.empty()){
            mx.insert(*mn.begin());
            mn.erase(mn.begin());
        }

        while(!mx.empty()&&!mn.empty()&&*mx.begin()>*mn.begin()){
            int a=*mx.begin();
            int b=*mn.begin();
            mx.erase(mx.begin());
            mn.erase(mn.begin());
            mx.insert(b);
            mn.insert(a);
        }
    }

    void insertNum(int num){
        if(mx.empty()||num<=*mx.begin())
            mx.insert(num);
        else
            mn.insert(num);

        balance();
    }

    void removeNum(int num){
        auto it=mx.find(num);
        if(it!=mx.end())
            mx.erase(it);
        else{
            it=mn.find(num);
            mn.erase(it);
        }

        balance();
    }

    vector<double> medianSlidingWindow(vector<int>& nums,int k){
        size=k/2;
        vector<double> ans;

        for(int i=0;i<nums.size();i++){
            insertNum(nums[i]);

            if(i>=k-1){

                if(k&1){
                    ans.push_back((double)*mn.begin());
                }else{
                    ans.push_back(((double)*mx.begin()+*mn.begin())/2.0);
                }

                removeNum(nums[i-k+1]);
            }
        }

        return ans;
    }
};