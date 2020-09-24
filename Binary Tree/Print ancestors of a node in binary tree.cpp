// Function should return all the ancestor of the target node
int found=0;
vector<int> ans;
void findNode(struct Node *root, int target)
{
    if(found)
    return;
    
    if(root->data==target)
    {
        found=1;
        return;
    }
    
    ans.push_back(root->data);
    if(root->left!=NULL && !found)
    findNode(root->left,target);
    
    if(root->right!=NULL && !found)
    findNode(root->right,target);
    
    if(!found)
    ans.pop_back();
}
vector<int> Ancestors(struct Node *root, int target)
{
     // Code here
     ans.clear();
     found=0;
     
     findNode(root,target);
     reverse(ans.begin(),ans.end());
     
     return ans;
}