class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //build adjList
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses);
        
        for (auto &prereq : prerequisites) {
            int course = prereq[0];
            int pre = prereq[1];

            indegree[course]++;
            adjList[pre].push_back(course);
        }

        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int courseCount = 0;
        while(!q.empty()) {
            int currCourse = q.front();
            q.pop();
            courseCount++;

            for (int &dependant : adjList[currCourse]) {
                indegree[dependant]--;
                if (indegree[dependant] == 0) {
                    q.push(dependant);
                }
            }
        }

        return courseCount == numCourses;
    }
};