class Solution {
public:
    struct TrieNode{
        vector<TrieNode*>child;
        bool isEnd;
        
        TrieNode(){
            child.resize(2);
            for(int i=0;i<2;i++)child[i]=nullptr;
            isEnd=false;
        }
    };
    
    struct Trie{
        TrieNode*root;
        Trie(){
            root=new TrieNode();
        }
        
        void  insertNum(int num){
            TrieNode*node=root; 
            for(int i=31;i>=0;i--){
                int bit=((num>>i)&1)?1:0;
                if(!node->child[bit])node->child[bit]=new TrieNode();
                node=node->child[bit];
            }
            node->isEnd=true;
        }

        int searchNum(int  num){
            TrieNode*node=root;
            int result=0;

            for(int i=31;i>=0;i--){
                int bit=((num>>i)&1)?1:0;
                if(node->child[bit]){
                    result+=(1<<i);
                    node=node->child[bit];
                }
                else if(node->child[1-bit])node=node->child[1-bit];
            }

            return result;
        }
    };
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(int i=0;i<nums.size();i++)t.insertNum(nums[i]);
        int result=0;
        for(int i=0;i<nums.size();i++){
            int opposite=(~nums[i]);
            result=max(result,t.searchNum(opposite));
        }

        return result;
    }
};