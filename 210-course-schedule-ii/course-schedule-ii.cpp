class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //topo sort
        //fill adjList and in degree or each node (number of dependencies for it)
        //the adjList has the nodes that are dependant of a certain node
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (auto prereq : prerequisites) {
            int course = prereq[0];
            int pre = prereq[1];

            adjList[pre].push_back(course); //course depends on pre
            inDegree[course]++; //one more dependency for the course
        }

        queue<int> q;
        //get the course that has no dependencies, to start with it
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ordered;
        while(!q.empty()) {
            int currCourse = q.front();
            q.pop();

            ordered.push_back(currCourse);
            for (int neigh : adjList[currCourse]) {
                inDegree[neigh]--;
                if (inDegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        return (ordered.size() == numCourses) ? ordered : vector<int>{};
    }
};