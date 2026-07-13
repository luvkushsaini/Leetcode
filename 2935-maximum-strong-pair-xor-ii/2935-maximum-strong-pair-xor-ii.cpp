class Solution {
public:
    struct TrieNode{
        vector<TrieNode*>child;
        int cnt;
        TrieNode(){
            child.resize(2,nullptr);
            cnt=0;
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
                node->child[bit]->cnt++;
                node=node->child[bit];
                
            }
            
        }

        int searchNum(int num){
            TrieNode*node=root;
            int result=0;
            for(int i=31;i>=0;i--){
                int bit=(num>>i&1);
                if(node->child[bit] && node->child[bit]->cnt>0){
                    result+=(1<<i);
                    node=node->child[bit];
                }
                else if(node->child[1-bit] &&  node->child[1-bit]->cnt>0 ){
                    node=node->child[1-bit];
                }
                else break;
            }

            return result;
        }

        void removeNum(int num){
            TrieNode*node=root;
            for(int i=31;i>=0;i--){
                int bit=(num>>i&1);
                if(node->child[bit]){
                    node->child[bit]->cnt--;
                }
                node=node->child[bit];
            }
        }
    };


    int maximumStrongPairXor(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        Trie t;

        int ans=INT_MIN;
        int j=0;
        for(int i=0;i<n;i++){
            int limit=2*nums[i];
            while(j<n && nums[j]<=limit)t.insertNum(nums[j]),j++;
            int opposite=(~nums[i]);
            ans=max(ans,t.searchNum(opposite));
            t.removeNum(nums[i]);
        }

        return ans;
    }
};