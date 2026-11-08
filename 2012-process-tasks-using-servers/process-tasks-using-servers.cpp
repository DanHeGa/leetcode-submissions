class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = tasks.size();
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> serversQ; //(weight, index)
        priority_queue<tuple<long long, long long, int>, vector<tuple<long long, long long, int>>, greater<tuple<long long, long long, int>>> busy; //(endtime, server weight, serverIdx)
        for (int i = 0; i < servers.size(); i++) { 
            serversQ.push({servers[i], i});
        }

        vector<int> assigned(n);

        for (int i = 0; i < n; i++) {
            //check if we can free servers
            while(!busy.empty() && get<0>(busy.top()) <= i) {
                auto [nextEnd, weight, serverIdx] = busy.top();
                busy.pop();
                serversQ.push({servers[serverIdx], serverIdx});
            }
            
            int selectedServerIdx = 0;
            int endTime = 0;
            if (!serversQ.empty()) { //if we have available server rn
                auto available = serversQ.top();
                serversQ.pop();

                selectedServerIdx = available.second;
                endTime = i + tasks[i];
                busy.push({endTime, servers[selectedServerIdx], selectedServerIdx});
            } else { //no available servers 
                auto [nextAvailable, weight, serverIdx] = busy.top(); //endtime, server idx
                busy.pop();

                selectedServerIdx = serverIdx;
                endTime = nextAvailable + tasks[i];
                busy.push({endTime, servers[serverIdx], serverIdx});
            }

            //put the assignation in the vector of assigned tasks
            assigned[i] = selectedServerIdx;
        }

        return assigned;
    }
};