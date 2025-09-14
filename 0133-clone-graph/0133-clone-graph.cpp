class Solution {
public:
    void DFS(Node* node, Node* clone_node, vector<Node*>& visited) {
        visited[node -> val] = clone_node;
        
        for(Node* x : node -> neighbors) {
            if(visited[x -> val] == NULL) {
                Node* clone = new Node(x->val);
                clone_node -> neighbors.push_back(clone);

                DFS(x, clone, visited);
            }
            else {
                clone_node->neighbors.push_back(visited[x -> val]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        
        Node* clone_node = new Node(node->val);

        vector<Node*> visited(101, NULL); 
        visited[node -> val] = clone_node;
        for(Node* x : node -> neighbors) {
            if(visited[x -> val] == NULL) {
                Node* clone = new Node(x -> val);
                clone_node -> neighbors.push_back(clone);

                DFS(x, clone, visited);
            } 
            else {
                clone_node -> neighbors.push_back(visited[x -> val]);
            }
        }        
        return clone_node;
    }
};
