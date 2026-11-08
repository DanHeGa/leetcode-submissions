class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> assigned(n, 0); //have a vector for each room meeting assignation 
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy; //{endTime, roomId}
        priority_queue<int, vector<int>, greater<int>> freeIds; //put the available rooms in the freeids pq
        for (int i = 0; i < n; i++) {
            freeIds.push(i);
        }

        //sort meetings in chronological order
        sort(meetings.begin(), meetings.end());

        for (auto meeting : meetings) { //[start time, end time]
            int startTime = meeting[0];
            int endTime = meeting[1];
            //first, free busy rooms
            while(!busy.empty() && busy.top().first <= startTime) {
                int newAvail = busy.top().second;
                busy.pop();

                freeIds.push(newAvail);
            }

            int assignedRoom = 0;
            if (!freeIds.empty()) { //if we have available rooms left
                int available = freeIds.top();
                freeIds.pop();

                assignedRoom = available;
                busy.push({endTime, available}); //add as busy up until end time
            } else { //no more of the n rooms are free right now
                pair<long long, int> nextFree = busy.top();
                busy.pop();

                assignedRoom = nextFree.second;
                long long newStart = nextFree.first;
                long long newEnd =  newStart + (endTime - startTime); 
                busy.push({newEnd, assignedRoom});
            }
            
            assigned[assignedRoom]++; //add a meeting to that room
        }

        int winningRoom = 0;
        for (int i = 0; i < n; i++) {
            if (assigned[i] > assigned[winningRoom]) {
                winningRoom = i;
            }
        }

        return winningRoom;
    }
};