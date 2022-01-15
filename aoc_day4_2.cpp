#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

using grid = vector<vector<int>>;

struct pos {
	int grid_num;
	int row, col;
};

void parse(vector<int> &draws, vector<grid> &grids, vector<grid> &row_col_counts, unordered_map<int, vector<pos>> &marked) {
	string input;
	getline(cin, input);
	stringstream sst(input);
	for (int d; sst >> d; ) {
		draws.push_back(d);
		if (sst.peek() == ',') {
			sst.ignore();
		}
	}

	int grid_num{0};
	while (getline(cin, input)) {
		// Skip 1 line
		if (!input.length()) {
			continue;
		}
		grid g(5, vector<int>(5, 0));
		grid rc(2, vector<int>(5, 0));
		for (int i = 0; i < 5; i++) {
			// get a row
			assert(input.length() != 0);
			stringstream ss(input);
			for (int j = 0; j < 5; j++) {
				int d;
				ss >> d;
				g[i][j] = d;
				marked[d].push_back({grid_num, i, j});
			}
			getline(cin, input);
		}
		grids.push_back(g);
		row_col_counts.push_back(rc);
		grid_num++;
	}
}
int main() {
	vector<int> draws;
	vector<grid> grids;
	vector<grid> row_col_counts;
	unordered_map<int, vector<pos>> marked;   
	parse(draws, grids, row_col_counts, marked);

	int ans{0};
	unordered_map<int, bool> won; 
	// Run the draw now
	for (auto d : draws) {
		for (auto &m : marked[d]) {
			int grid_num = m.grid_num;
			int row = m.row;
			int col = m.col;

			// Mark the grid with 0 for the draw
			auto &g = grids[grid_num];
			g[row][col] = 0;
			auto &rc_count = row_col_counts[grid_num];
			rc_count[0][row]++;
			rc_count[1][col]++;

			if (!won[grid_num] and (rc_count[0][row] == 5 || rc_count[1][col] == 5)) {
				ans = 0;
				won[grid_num] = true;
				cout << "Ans Grid Num = " << grid_num << " Num = " << d  << endl;
				for (auto r : g) {
					for (auto c : r) {
						ans += c;
					}
				}
				ans *= d;
			}
		}         
	}

	cout << "Ans = " << ans << endl;
	return 0;
}
