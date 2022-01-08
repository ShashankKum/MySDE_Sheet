//for getting the bottom view we need to get the horizontal distance of each node and it will be a new data type in the structure of tree, ut if it is 
  not mentioned than we push the horizontal distance and node in queue used for doing bfs traversal.
//if we traverse left child than horizontal dist will be (hor dist of root node-1), and for right (hor dist of root node+1),we keep on adding it in map
  with distance as key and node data as its value, as we can have unique key so whenever a same horizontal position is added the previous one is replaced.

// Method that returns the bottom view.
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
            mp[val]=b->data; //we will make horizontal distance as key and node data as its value
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
vector <int> bottomView(Node *root)
{
   return bfs(root);
}