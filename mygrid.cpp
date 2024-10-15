#include <iostream>
#include <vector>
#include <cassert>
#include <gtest/gtest.h>
#include <algorithm>

struct Grid {
    Grid(int w, int h) : w_(w), h_(h) {
        store_.resize(w_ * h_);
        std::fill(store_.begin(), store_.end(), 0);
    }
    // Return iterator pair for start, end of row
    auto get_row(size_t row);
    auto print_grid();
    std::vector<int> store_;
    int w_;
    int h_;
};


auto Grid::get_row(size_t row) {
    auto left = store_.begin() + h_ * row;
    auto right = left + w_;
    return std::make_pair(left, right); 
}

auto Grid::print_grid() {
    for (size_t row = 0; row < h_; row++) {
        auto cur_row = get_row(row);
        std::for_each(cur_row.first, cur_row.second, [](const auto &n){std::cout << n << ' ';});
        std::cout << "\n";
    }
    std::cout << std::endl;
}

int main() {
    Grid g(20, 20);
    g.print_grid();
    auto row = g.get_row(3);
    auto myrand = [](){
        return std::rand() % 100;
    };
    std::generate(row.first, row.second, myrand);
    g.print_grid();
    return 0;
}