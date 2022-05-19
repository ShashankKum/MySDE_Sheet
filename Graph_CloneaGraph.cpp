//In this graph edges are not connected we just have nodes and there neighbouring nodes using which we need to traverse.
//We cant create the refrence of old node and say that it is copied we need to create a new node.
//We make use of a map which is having old node and new node cloned for the old node, where old node being the key.
//We check if the node is already cloned we simply push in neighbor or else we do dfs(where we create a new clone and also add it to the map).


class Solution {
public:
    Node* dfs(Node* node,unordered_map<Node*,Node*> &mp){
        Node* n1 = new Node(node->val);
        mp[node]=n1;
        for(auto x:node->neighbors){
            if(mp.find(x)!=mp.end())  //it means we have already cloned this node, so simply push the same to neighbors
                n1->neighbors.push_back(mp[x]);
            else
                n1->neighbors.push_back(dfs(x,mp));
        }
        return n1;
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<Node*,Node*> mp;
        return dfs(node,mp);
    }
};