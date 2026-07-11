class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses);

        for (auto &prereq : prerequisites) {
            int course = prereq[0];
            int pre = prereq[1];

            indegree[course]++; //how many courses this course depends on
            adjList[pre].push_back(course); //add all the pre dependants  in the adjList
        }

        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> orderedCourses;
        while(!q.empty()) {
            int currCourse = q.front();
            q.pop();
            orderedCourses.push_back(currCourse);

            for (int &dependant : adjList[currCourse]) {
                indegree[dependant]--;
                if (indegree[dependant] == 0) {
                    q.push(dependant);
                }
            }
        }

        if (orderedCourses.size() == numCourses) {
            return orderedCourses;
        } else {
            return {};
        }
    }
};