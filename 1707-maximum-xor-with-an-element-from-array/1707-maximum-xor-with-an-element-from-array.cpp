class Solution {
public:

    struct TrieNode{
        vector<TrieNode*>child;
        bool isEnd;
        TrieNode(){
            child.resize(2,nullptr);
            isEnd=false;
        }
    };

    struct Trie{
        TrieNode*root;
        Trie(){
            root=new TrieNode();
        }
        void insertNum(int num){
            TrieNode*node=root;
            for(int i=31;i>=0;i--){
                int bit=(num>>i&1);
                if(!node->child[bit]){
                    node->child[bit]=new TrieNode();
                }
                node=node->child[bit];
            }
        }

        int searchNum(int num){
            TrieNode*node=root;
            int result=0;
            for(int i=31;i>=0;i--){
                int bit=(num>>i&1);
                if(node->child[bit]){
                    result+=(1<<i);
                    node=node->child[bit];
                }
                else if(node->child[1-bit]){
                    node=node->child[1-bit];
                }
                else break;
            }
            return result;
        }
    };


    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int m=queries.size();
        vector<int>ans(m);
        vector<vector<int>>newQueries;
        for(int i=0;i<m;i++){
            newQueries.push_back({queries[i][1],queries[i][0],i});
        }
        sort(newQueries.begin(),newQueries.end());
        int j=0;
        Trie t;
        int mn=*min_element(nums.begin(),nums.end());

        for(int i=0;i<m;i++){
            int pos=newQueries[i][2];
            int num=newQueries[i][1];
            int limit=newQueries[i][0];
            if(mn>limit){
                ans[pos]=-1;
                continue;
            }
            while(j<n && nums[j]<=limit)t.insertNum(nums[j]),j++;
            int opposite=(~num);
            ans[pos]=t.searchNum(opposite);
        }

        return ans;

    }
};