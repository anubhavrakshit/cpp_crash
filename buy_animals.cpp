#include <iostream>
#include <unordered_map>
using namespace std;
enum Animal {Horse, Pig, Rabbit};
void buyAnimal(float totalMoney, unordered_map<Animal, int> &buy,
               unordered_map<Animal, float> &price_map) {
  if (!totalMoney) {
    for (auto [k, v] : buy) {
      string animal;
      if (k == Horse) {
        animal = "Horse";
      } else if (k == Pig) {
        animal = "Pig";
      } else {
        animal = "Rabbit";
      }
      cout << animal << ": " << v << " ";
    }
    cout << endl;
    return;
  }

  for (auto [animal, price] : price_map) {
    if (price <= totalMoney) {
        buy[animal]++;
        buyAnimal(totalMoney - price, buy, price_map);
        buy[animal]--;
    }
  }
}

int main() {
  unordered_map<Animal, int> buy;
  unordered_map<Animal, float> price = {{Horse, 10}, {Pig, 3}, {Rabbit, 2}};
  float totalMoney = 20;
  buyAnimal(totalMoney, buy, price);
  return 0;
}