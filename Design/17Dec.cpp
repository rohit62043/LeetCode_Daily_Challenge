// 2353. Design a Food Rating System
class FoodRatings {
public:
     // Map food with its rating.
    unordered_map<string, int> foodRatingMap;
    // Map food with cuisine it belongs to.
    unordered_map<string, string> foodCuisineMap;
    unordered_map<string, set<pair<int,string>>> cuisineFoodMap;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            foodCuisineMap[foods[i]]=cuisines[i];
            foodRatingMap[foods[i]]=ratings[i];
            cuisineFoodMap[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        int oldRating= foodRatingMap[food];
        auto it=cuisineFoodMap[foodCuisineMap[food]].find({-oldRating,food});
        cuisineFoodMap[foodCuisineMap[food]].erase(it);
        foodRatingMap[food]=newRating;
        cuisineFoodMap[foodCuisineMap[food]].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        auto temp = begin(cuisineFoodMap[cuisine])->second;

        return temp;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
