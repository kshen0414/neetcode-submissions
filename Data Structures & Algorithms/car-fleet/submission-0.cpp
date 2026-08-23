class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        /**
            Algorithm:
            Combine position and speed into a vector pair
            Computer arrival time = (target - position) / speed
            Sort the vector pair
        **/

        vector<pair<int, double>> cars(speed.size());
        for(int i = 0; i < speed.size(); i++){
            double arrivalTime = (double) (target - position[i]) / (double) speed[i];
            pair<int, double> newPair = {position[i], arrivalTime};
            cars[i] = newPair;
        }

        // sorts by the first element, i.e., position
        sort(cars.begin(), cars.end());

        int numFleets = 1;
        double earliestTime = cars.back().second;

        // iterate the array backwards
        for(int i = cars.size()-2; i>=0; i--){
            if(cars[i].second > earliestTime){
                numFleets++;
                earliestTime = cars[i].second;
            }
        }

        return numFleets;
    }
};
