void get(Node* root,int level,map<int,vector<int>>& m)
{
    m[level].push_back(root->data);
    
    if(root->left!=NULL)
    get(root->left,level+1,m);
    
    if(root->right!=NULL)
    get(root->right,level+1,m);
}
vector<vector<int>> levelOrder(Node* node)
{
  //Your code here
    map<int,vector<int>> m;
    get(node,0,m);
    
    vector<vector<int>> v;
    
    for(auto t:m)
    v.push_back(t.second);
    
    return v;
}
