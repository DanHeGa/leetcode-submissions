class Solution {
private:
    vector<vector<string>> res;
    vector<vector<int>> predecessors; // predecessors[i] guarda los IDs predecesores del nodo i

public:
    void backtrackPaths(int currId, int beginId, vector<int>& path, const vector<string>& idToWord) {
        if (currId == beginId) {
            vector<string> singleRes;
            for (int i = path.size() - 1; i >= 0; i--) {
                singleRes.push_back(idToWord[path[i]]);
            }
            res.push_back(singleRes);
            return;
        }

        for (int predId : predecessors[currId]) {
            path.push_back(predId);
            backtrackPaths(predId, beginId, path, idToWord);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // 1. Asignar un ID entero a cada palabra
        unordered_map<string, int> wordToId;
        vector<string> idToWord;

        auto getOrAddId = [&](const string& w) {
            if (!wordToId.count(w)) {
                wordToId[w] = idToWord.size();
                idToWord.push_back(w);
            }
            return wordToId[w];
        };

        int beginId = getOrAddId(beginWord);
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return {};

        for (const string& w : wordList) {
            getOrAddId(w);
        }

        int endId = wordToId[endWord];
        int n = idToWord.size();

        // Data structures usando IDs numéricos
        predecessors.resize(n);
        vector<int> distance(n, INT_MAX);
        queue<int> q;

        q.push(beginId);
        distance[beginId] = 0;

        bool foundFinal = false;

        // BFS en el grafo indexado
        while (!q.empty() && !foundFinal) {
            int qSize = q.size();

            for (int i = 0; i < qSize; i++) {
                int currId = q.front();
                q.pop();

                string currWord = idToWord[currId];
                int currDist = distance[currId];

                // Generar transformaciones
                for (int j = 0; j < currWord.size(); j++) {
                    char ogChar = currWord[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == ogChar) continue;
                        currWord[j] = c;

                        if (wordToId.count(currWord)) {
                            int targetId = wordToId[currWord];

                            // Si la encontramos en un nivel más corto o igual
                            if (distance[targetId] >= currDist + 1) {
                                if (distance[targetId] > currDist + 1) {
                                    distance[targetId] = currDist + 1;
                                    q.push(targetId);
                                }
                                predecessors[targetId].push_back(currId);

                                if (targetId == endId) {
                                    foundFinal = true;
                                }
                            }
                        }
                    }
                    currWord[j] = ogChar;
                }
            }
        }

        // 2. Reconstrucción con DFS si se encontró la palabra destino
        if (foundFinal) {
            vector<int> path = {endId};
            backtrackPaths(endId, beginId, path, idToWord);
        }

        return res;
    }
};