//In this we use same idea as bottom view just we check if a particular horizontal distance is already present we dont add a new one as we need top view.

vector<int> bfs(Node *root){
    map <int,int> mp; //values will be sorted by key(horizontal distance),so leftmost node val first
    vector <int> ve; //it will have the bottom view from left to right
    queue <pair<Node*,int>> q; //contains node and its horizontal distance
    q.push({root,0}); //root node horizontal dist initialized with 0
    while(!q.empty()){ //it will do a bfs traversal making use of queue
            pair<Node*,int> a=q.front();
            q.pop();
            Node* b=a.first;
            int val=a.second;
            if(mp.find(val)==mp.end()) //if a position is already present we will not insert further
            mp[val]=b->data;
            if(b->left!=NULL){
                q.push({b->left,val-1}); //horz dist of left child will be val-1
            }
            if(b->right!=NULL){
                q.push({b->right,val+1}); ////horz dist of left child will be val+1
            }
    }
    auto it=mp.begin();
    while(it!=mp.end()){
        ve.push_back(it->second); //values sorted by horiz dist will be pushed in vector to be returned
        it++;
    }
    return ve;
}
// function should print the topView of the binary tree
vector<int> topView(struct Node *root)
{
   return bfs(root);
}