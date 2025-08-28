/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<int,vector<int>>graph;
    void buildgraph(TreeNode* node,TreeNode* parent ){
        if(node==nullptr) return;
        if(parent){
            graph[node->val].push_back(parent->val);
            graph[parent->val].push_back(node->val);
        }
        buildgraph(node->left,node);
        buildgraph(node->right,node);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        buildgraph(root, nullptr);
        unordered_set<int>visited;
        queue<int>q;
        q.push(start);
        visited.insert(start);
        int min = -1;
        while(!q.empty()){
            int k = q.size();
            min++;
            for(int i=0;i<k;i++){
                int node = q.front();
                q.pop();
                for(auto neigh : graph[node]){
                    if(!visited.count(neigh)){
                        q.push(neigh);
                        visited.insert(neigh);
                    }
                }
            }
        }
        return min;
    }
};

// 1 - 3,5
// 3-  1,10,6
// 5 -1 ,4
// 4 - 5, 9,2

// minute 0 - 3 
// 1 - 1, 10, 6. visited : 3,1,10,6
// 2 - 5
// 3 - 4,
// 4 - 9,2


