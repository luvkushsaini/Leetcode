class Solution {
public:

    vector<bool>isPrime;
    vector<int>v;
    void sieve(int num){
        isPrime.assign(num+1,true);
        isPrime[0]=false;
        isPrime[1]=false;
        for(int i=2;i*i<=num;i++){
            if(isPrime[i]==false)continue;
            if(isPrime[i]){
                int j=2;
                while((i*j)<=num){
                    int nm=i*j;
                    isPrime[nm]=false;
                    j++;
                }
            }

        }
    }

    vector<int>pushAllPrimes(int num){
        v.clear();
        for(int i=2;i*i<=num;i++){
            if(num%i==0){
                v.push_back(i);
                while(num%i==0)num/=i;
            }
        }

        if(num>1)v.push_back(num);
        return v;
    }

    vector<vector<int>>allPrimes;


    int findValidSplit(vector<int>& nums) {
        int n=nums.size();
        sieve(1e6);
        allPrimes.resize(n);
        for(int i=0;i<n;i++){
            int num=nums[i];
            allPrimes[i]=pushAllPrimes(num);
            for(int j=0;j<allPrimes[i].size();j++)cout<<allPrimes[i][j]<<" ";
            cout<<endl;
        }

        unordered_map<int,int>farPosition;

        for(int i=n-1;i>=0;i--){
            for(int prime:allPrimes[i]){
                if(!farPosition.count(prime))farPosition[prime]=i;
            }
        }


        int ans=0;
        for(int i=0;i<n;i++){
            for(int num:allPrimes[i]){
                ans=max(ans,farPosition[num]);
            }
            if(ans==i){
                break;
            }
        }

        if(ans==-1)return -1;
        if(ans==n-1)return -1;
        return ans;
    }


};