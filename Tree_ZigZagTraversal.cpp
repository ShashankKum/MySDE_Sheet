//To perform zigzagLevelOrder we need two stacks one stack nodes we use to push there childrens in other stack and than when after traversing one complete
  level the first stack becomes empty we swap the stack to again make it in the same condition.
//Once we push the left->right and in other right to left.

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       stack <TreeNode*> s1;
        stack <TreeNode*> s2;
        TreeNode *cur;
        bool flag=1;
        vector <int> a;
        vector <vector<int>> v;
        if(!root) return v;
       s1.push(root);
        while(!s1.empty()){
            int l=s1.size(); //size of current stack needs to be declared initially as it will keep changing 
            a.clear();  //used to clear the initial stored values vector a
            for(int i=0;i<l;i++){
            if(flag==0){
            cur=s1.top(); s1.pop();
            a.push_back(cur->val);
            if(cur->right) s2.push(cur->right); //push right to left
            if(cur->left)  s2.push(cur->left);
            } 
            else{
            cur=s1.top(); s1.pop();
            a.push_back(cur->val);
            if(cur->left) s2.push(cur->left); //push left to right
            if(cur->right) s2.push(cur->right);
            }
        }
            v.push_back(a);
            flag=!flag; //flag will vary for each level
            swap(s1,s2); //This function is used to swap the contents of one stack with another stack of same type but the size may vary.
        }
        return v;
    }
};