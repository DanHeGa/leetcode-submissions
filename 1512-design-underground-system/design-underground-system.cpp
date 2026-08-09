class UndergroundSystem {
private:
    unordered_map<string, pair<double, int>> timeRecords;
    unordered_map<int, pair<string, double>> checkInRecords;

public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        //add it to the checkIn registry
        pair<string, double> checkInTime = {stationName, t};
        checkInRecords[id] = checkInTime;
    }
    
    void checkOut(int id, string stationName, int t) {
        //get startstation and startTime from checkin map with input id
        pair<string, double> userCheckIn = checkInRecords[id];
        string travelId = userCheckIn.first +  '-' + stationName; //checkIn and checkout station name
        double travelTime = t - userCheckIn.second;

        if (timeRecords.contains(travelId)) {
            auto [totalTime, totalRegistries] = timeRecords[travelId];
            totalTime += travelTime;
            totalRegistries += 1;
            timeRecords[travelId] = {totalTime, totalRegistries};
        } else {    
            timeRecords[travelId] = {travelTime, 1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string travelId = startStation + '-' + endStation;
        auto [totalTime, totalRegistries] = timeRecords[travelId];
        return totalTime / totalRegistries;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */