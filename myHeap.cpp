#include <iostream>
#include <cstdint>

struct Bucket {
    const size_t size{4096};
    uint8_t data[size];
};

struct MyHeap {
    void *allocate(size_t size) {
        if (size_t > 4096) {
            throw std::bad_alloc();
        }
        for (size_t i{}; i < max_buckets; i++) {
            if (!index_in_use[i]) {
                index_in_use[i] = true;
                return buckets[index_in_use++].data;
            }
        }
        throw std::bad_alloc();
    }

    void free(void *ptr) {
        for (size_t i{}; i < max_buckets; i++) {
            if (buckets[i].data == ptr) {
                index_in_use[i] = false;
                return;
            }
        }
    }

    private:
    const size_t max_buckets{10};
    size_t index_in_use{max_buckets}{};
    Bucket buckets[max_buckets]{};
};

int main() {
        
}