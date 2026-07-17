class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, int> indegree;
        unordered_map<char, vector<char>> adjList;

        for (string word : words) {
            for (char c : word) {
                indegree[c] = 0;
                adjList[c];
            }
        }


        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i]; //smaller letter
            string w2 = words[i + 1]; //dependant 

            int minLen = min(w1.length(), w2.length());

            //check we can actually continue
            if (w1.length() > w2.length() && w1.substr(0, minLen) == w2) {
                cout << "Entered here" << endl;
                return "";
            }

            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    indegree[w2[j]]++;
                    adjList[w1[j]].push_back(w2[j]); //add new dependant node to w1 char dependent nodes list (represented in the adjList)
                    break;
                }
            }
        }

        //initialize queue with 0-indegree nodes (letters with NO dependencies)
        queue<char> q;
        string res = "";
        for (auto ele : indegree) {
            if (ele.second == 0) {
                q.push(ele.first);
            }
        }

        cout << endl;

        while(!q.empty()) {
            char smallerLetter = q.front();
            q.pop();
            res += smallerLetter;

            for (char dependant : adjList[smallerLetter]) {
                indegree[dependant]--;
                if (indegree[dependant] == 0) {
                    q.push(dependant);
                }
            }
        }

        return res.length() == indegree.size() ? res : "";

    }
};