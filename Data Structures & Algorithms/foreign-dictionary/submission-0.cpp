class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        /**
            Algo: Topological Sort
        **/

        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> inDegree;

        for (auto &word : words){
            for (auto &c : word){
                graph[c] = vector<char>();
                inDegree[c] = 0;
            }
        }

        string result = "";

        for (int i = 0; i < words.size() - 1; i++){
            string w1 = words[i];
            string w2 = words[i + 1];

            if (w1.size() > w2.size() && w1.find(w2) == 0){
                return "";
            }

            for (int j = 0; j < min(w1.length(), w2.length()); j++){
                if(w1[j] != w2[j]){
                    graph[w1[j]].push_back(w2[j]);
                    inDegree[w2[j]]++;
                    break;
                }
            }


        }

        // bfs
        queue<char> q;

        for (auto &inDeg : inDegree){
            if (inDeg.second == 0) {
                q.push(inDeg.first);
            }
        }

        while(!q.empty()){
            char top = q.front();
            q.pop();

            result += top;
            for (auto &neighbour : graph[top]){
                inDegree[neighbour]--;
                if(!inDegree[neighbour]){
                    q.push(neighbour);
                }
            }
        }

        return result.size() == inDegree.size() ? result : "";
    }
};
