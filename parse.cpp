#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	string input;
	getline(cin, input);
	vector<int> draws;
	stringstream sst(input);
	for (int d; sst >> d; ) {
		draws.push_back(d);
		if (sst.peek() == ',') {
			sst.ignore();
		}
	}

	using grid = vector<vector<int>>;
	vector<grid> grids;
	while (getline(cin, input)) {
		// Skip 1 line
		if (!input.length()) {
			continue;
		}
		grid g(5, vector<int>(5, 0));
		for (int i = 0; i < 5; i++) {
			// get a row
			assert(input.length() != 0);
			stringstream ss(input);
			for (int j = 0; j < 5; j++) {
				int d;
				ss >> d;
				g[i][j] = d;
			}
			getline(cin, input);
		}
		grids.push_back(g);
	}

	cout << "Num grids = " << grids.size() << endl;
	return 0;
}
