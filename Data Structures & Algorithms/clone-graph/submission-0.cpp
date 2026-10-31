/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        /**
            Algo: DFS

            Description:
            - clone a graph with same node values and connections
            - but they must be different objects in memory


        **/

        if (node == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> clones;
        return dfs(node, clones);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& clones) {
        if (clones.count(node) == 1) {  // check clone in graph
            return clones[node];
        }

        Node* clonedNode = new Node(node->val);

        clones[node] = clonedNode;

        for (Node* neighbor : node->neighbors) {
            Node* clonedNeighbor = dfs(neighbor, clones);
            clonedNode->neighbors.push_back(clonedNeighbor);
        }

        return clonedNode;
    }
};
