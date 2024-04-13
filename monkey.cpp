long long calc_time(vector<int>& piles, long long eat_speed) {
  long long total_time{0};
  for (auto p : piles) {
    if (p % eat_speed) {
      total_time++;
    }
    total_time += p / eat_speed; 
  }
  return total_time;
}
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       long long low = 1, high = piles[0];
       for (long long p : piles) {
        low = min(p, low);
        high = max(p, high);
       }

       while (low <= high) {
        auto mid = (low + high) / 2;
        auto time_req = calc_time(piles, mid);
        if (time_req <= h) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
       }
       return high + 1;
    }
};