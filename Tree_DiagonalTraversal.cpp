//If we move right we stay in the same diagonal but if we move left the diagonal gets changed, we use this logic.
//We will use a map with its key being the diagoanl number and val being a vector of values
//We get it done in O(N) time and O(N) extra space.

map<int,vector<int>> mp;
void recur(Node *root,int d){
    if(root==NULL)  return;
    mp[d].push_back(root->data);
    recur(root->left,d+1);
    recur(root->right,d);
}
vector<int> diagonal(Node *root)
{
   mp.clear();
   vector<int> v;
   recur(root,0);
   for(auto p:mp){
       for(auto x:p.second){
           v.push_back(x);
       }
   }
   return v;
}