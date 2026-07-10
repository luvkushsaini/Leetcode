class TreeAncestor {
public://Binary Lifting 
   vector<vector<int>>ancestors;
   int row,col;
    TreeAncestor(int n, vector<int>& parent) {
            row=n;
            col=log2(n)+1;
        ancestors.resize(row,vector<int>(col,-1));
        for(int node=0;node<n;node++){
            ancestors[node][0]=parent[node];
        }

        for(int j=1;j<col;j++){
            for(int node=0;node<n;node++){
                if(ancestors[node][j-1]!=-1){
                ancestors[node][j]=ancestors[ancestors[node][j-1]][j-1];}
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int j=0;j<col;j++){
            if(1&(k>>j)){
                node=ancestors[node][j];
            }
            if(node==-1)return node;
        }

        return node;
    }
};


/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */