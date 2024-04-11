#include <deque>
#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <queue>

namespace {
class Document {
public:
  Document(std::string name) : name_{name} {}
  auto getName() { return name_; }

private:
  std::string name_;
};

struct Hit {
  float rank_{};
  std::shared_ptr<Document> document_;
};

template <typename It>
auto sort_hits(It begin, It end, size_t k) -> std::vector<Hit> {
  auto comp = [](const Hit& a, const Hit& b) {
    return a.rank_ > b.rank_;
  };
  std::priority_queue<Hit, std::vector<Hit>, decltype(comp)> pq{comp};
  for (auto it = begin; it != end; it++) {
    if (pq.size() < k) {
      pq.push(*it);
    } else {
      if (it->rank_ > pq.top().rank_) {
        pq.pop();
        pq.push(*it);
      }
    }
  }
  auto k_hits = std::vector<Hit>{};
  while (!pq.empty()) {
    k_hits.push_back(pq.top());
    pq.pop();
  }
  std::reverse(k_hits.begin(), k_hits.end());
  return k_hits;
};

auto generate_rand_hit(std::string name) {
  auto hit = Hit{};
  hit.document_ = std::make_shared<Document>(name);
  hit.rank_ = static_cast<float>(rand())/static_cast<float>(RAND_MAX);
  return hit;
}

} // end namespace

TEST(PriorityQ, Top20Hits) {
  std::deque<Hit> rand_hits;
  for (int i = 1; i < 100000; i++) {
    std::string prefix{"HIT-"};
    rand_hits.push_front(generate_rand_hit(prefix + std::to_string(i)));
  }

  auto top_twenty_hits = sort_hits(rand_hits.begin(), rand_hits.end(), 20);
  //for (auto& hit : top_twenty_hits) {
  //  std::cout << hit.document_->getName() << " : " << hit.rank_ << std::endl;
  //}
  for (int i = 0; i < top_twenty_hits.size() - 1; i++) {
    ASSERT_TRUE(top_twenty_hits[i].rank_ > top_twenty_hits[i + 1].rank_);
  }
}

#if 0
void test_run() {
  std::deque<Hit> rand_hits;
  for (int i = 1; i < 1000; i++) {
    string prefix{"HIT-"};
    rand_hits.push_front(prefix + generate_rand_hit(std::to_string(i)));
  }

  auto top_twenty_hits = sort_hits(rand_hits.begin(), rand_hits.end(), 20);
  for (auto& hit : top_twenty_hits) {
    cout << hit.document_ << " : " << hit.rank_ << std::endl;
  }
  for (int i = 0; i < top_twenty_hits.size() - 1; i++) {
    ASSERT_TRUE(top_twenty_hits[i].rank_ > top_twenty_hits[i + 1].rank_);
  }
}
#endif

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}