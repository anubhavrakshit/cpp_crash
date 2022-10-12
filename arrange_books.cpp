#include <iostream>
#include <vector>
using namespace std;

vector<int> arrange_books(vector<int> &books) {
    vector<int> alex_books, bob_books;
    for (int i = 0; i < books.size(); i++) {
        if (books[i] % 2 == 0) {
            bob_books.push_back(books[i]);
        } else {
            alex_books.push_back(books[i]);
        }
    }
    sort(alex_books.begin(), alex_books.end());
    sort(bob_books.begin(), bob_books.end(), std::greater());

    int b{0}, a{0};
    vector<int> sort_books;
    for (int i = 0; i < books.size(); i++) {
        if (books[i] % 2 == 0) {
            sort_books.push_back(bob_books[b++]);
        } else {
            sort_books.push_back(alex_books[a++]);
        }
    }
    return sort_books;
}

int main() {
  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;
    // Stores the books worth
    vector<int> books(N);
    for (int i = 0; i < N; i++) {
      cin >> books[i];
    }
   
    cout << "Case #" << testCase << ": ";
    vector<int> sort_books = arrange_books(books);
    for (int i = 0; i < sort_books.size(); i++) {
      cout << sort_books[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
