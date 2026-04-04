class Solution {
public:

/*
---------------------------------- TRIE + DFS APPROACH ----------------------------------

Trie:
- A Trie is a tree-like data structure used to store words.
- Each node represents a character.
- Paths from root → form words.
- Common prefixes are shared → saves time during search.

Why Trie here?
- Brute force: For each word, we run DFS on the board.
  Time = O(W * n * m * 3^L)   ❌ (very slow)

- Optimized (Trie):
  - Insert all words into Trie → O(W * L)
  - Run ONE DFS on board and match characters with Trie
  - Stop early if prefix not found (pruning)

DFS Logic:
- Start from every cell → O(n * m)
- At each step:
    - 4 directions initially
    - Then at most 3 (cannot go back to previous cell)
- Max depth = L (length of longest word)
→ DFS = O(n * m * 3^L)

Total Time Complexity:
→ O(W * L + n * m * 3^L)

Space Complexity:
- Trie: O(W * L)
- Recursion stack: O(L)

Key Optimization:
- Trie avoids repeating DFS for each word
- Prunes invalid paths early using prefix check
*/

    struct TrieNode{
        TrieNode*children[26];
        bool isEndOfWord;

        TrieNode(){
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isEndOfWord=false;
        }
        
    };

    void insertWord(string word, TrieNode*root){
        TrieNode*curr=root;

        for(char ch:word){
            int c=ch-'a';
            if(curr->children[c]==NULL){
                curr->children[c]=new TrieNode();
            }
            curr=curr->children[c];
        }
        curr->isEndOfWord=true;
    }

//------------------------------------

    int n,m, size;

    vector<string>ans;
    vector<int>row={-1,1,0,0};
    vector<int>col={0,0,-1,1};



    void solve(int i,int j,TrieNode*node,string &s,vector<vector<char>>& board){

        if(node->isEndOfWord){
            ans.push_back(s);
            node->isEndOfWord=false; // to avoid duplicates
        }

        for(int k=0;k<4;k++){
            int new_row=i+row[k];
            int new_col=j+col[k];

            if(new_row<n && new_row>=0 && new_col<m && new_col>=0 && board[new_row][new_col]!='#' ){
            char ch=board[new_row][new_col];
            int pos=ch-'a';
            board[new_row][new_col]='#';

            if(node->children[pos]!=NULL){
                s.push_back(ch);
                solve(new_row,new_col,node->children[pos],s,board);
                s.pop_back();
            }
            board[new_row][new_col]=ch;
            }

        }

        return ;

    }



    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       n=board.size();
       m=board[0].size();
       size=words.size();
       TrieNode*root=new TrieNode();

       for(int i=0;i<size;i++){
        insertWord(words[i],root);
       }

       string s="";

       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int  ch=board[i][j];
            int pos=ch-'a';
            board[i][j]='#';

            if(root->children[pos]!=NULL){
                s.push_back(ch);
                solve(i,j,root->children[pos],s,board);
                s.pop_back();
            }
            board[i][j]=ch;
        }
       }

       return ans;



    }
};