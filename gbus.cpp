#include <iostream>
#include <vector>
using namespace std;

vector<int> numberOfGBusesPerCity(vector<int> cities,
                                  vector<pair<int, int>> gBuses) {
  vector<int> numberOfGBuses;
  // TODO: Complete this function to return the number of GBuses serving each of
  // the specified cities.
  vector<int> prefix_arr(5002, 0);

  for (auto &c : gBuses) {
        prefix_arr[c.first]++;
        prefix_arr[c.second + 1]--;
  }
  for (int i = 1; i < prefix_arr.size(); i++) {
    prefix_arr[i] += prefix_arr[i - 1];
  }

  for (auto c : cities) {
        numberOfGBuses.push_back(prefix_arr[c]);
  }
  return numberOfGBuses;
}

int main() {
  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;
    // Stores the range of cities served by every GBus.
    vector<pair<int, int>> gBuses(N);
    for (int i = 0; i < N; i++) {
      cin >> gBuses[i].first >> gBuses[i].second;
    }
    int P;
    cin >> P;
    vector<int> cities(P);
    for (int i = 0; i < P; i++) {
      cin >> cities[i];
    }
    cout << "Case #" << testCase << ": ";
    vector<int> numberOfGBuses = numberOfGBusesPerCity(cities, gBuses);
    for (int i = 0; i < numberOfGBuses.size(); i++) {
      cout << numberOfGBuses[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
