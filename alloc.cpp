// Arena allocator
// We will create a custom allocator that allocates memory in chunks. This is
// useful when we have a lot of small objects that are created and destroyed
// frequently. Instead of calling new and delete for each object, we can
// allocate a large chunk of memory and manage it ourselves. This is called an
// arena allocator.

// Design of the arena allocator
// The arena allocator will have the following design:
// - The arena allocator will allocate memory in chunks.
// - The size of each chunk will be specified by the user.
// - The arena allocator will keep track of the current chunk and the current
//   position in the chunk.
// - When the current chunk is full, the arena allocator will allocate a new
//   chunk.
// - The arena allocator will not free memory until it is destroyed.

// The arena allocator will have the following interface:
// - The constructor will take the size of the chunk as an argument.
// - The allocate function will allocate memory from the current chunk.
// - The deallocate function will do nothing, as the arena allocator does not
//   free memory.
// - The destroy function will free all the memory allocated by the arena
//   allocator.
// - Test cases for the arena allocator will be provided.
#include <iostream>
#include <string>
#include <cassert>
#include <sys/mman.h>
#include <atomic>

class ArenaAllocator {
    char* origChunk{nullptr};
    char* currentChunk{nullptr};
    std::atomic<char*> currentPosition{nullptr};
    size_t chunkSize{0};

    public:
    ArenaAllocator(size_t chunkSize) : chunkSize{chunkSize} {
        currentChunk = static_cast<char*>(mmap(nullptr, chunkSize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));
        if (currentChunk == MAP_FAILED) {
            std::cerr << "Failed to allocate memory" << std::endl;
            std::abort();
        }
        origChunk = currentChunk;
        currentPosition.store(currentChunk);
    }
    ArenaAllocator(const ArenaAllocator&) = delete;
    ArenaAllocator& operator=(const ArenaAllocator&) = delete;
    ArenaAllocator(ArenaAllocator&& other) noexcept : origChunk{other.origChunk}, currentChunk{other.currentChunk}, currentPosition{other.currentPosition.load()}, chunkSize{other.chunkSize} {
        other.origChunk = nullptr;
        other.currentChunk = nullptr;
        other.currentPosition.store(nullptr);
        other.chunkSize = 0;
    }

    void* allocate(size_t size) {
        char* oldPosition = currentPosition.load();
        char* newPosition = oldPosition + size;

        while (!currentPosition.compare_exchange_weak(oldPosition, newPosition)) {
            newPosition = oldPosition + size;
            if (newPosition > origChunk + chunkSize) {
                std::cerr << "Out of memory" << std::endl;
                std::abort();
            }
        }

        if (newPosition > origChunk + chunkSize) {
            std::cerr << "Out of memory" << std::endl;
            std::abort();
        }

        return oldPosition;
    }

    void deallocate(void* ptr) {
        // Do nothing
    }

    void destroy() {
        (void)munmap(origChunk, chunkSize);
    }

    ~ArenaAllocator() {
        destroy();
    }
};

int main() {
    // Create an arena allocator with a chunk size of 1024 bytes
    ArenaAllocator allocator(1024);

    // Allocate memory for an integer
    int* intPtr = static_cast<int*>(allocator.allocate(sizeof(int)));
    *intPtr = 42;
    std::cout << "Allocated integer: " << *intPtr << std::endl;

    // Allocate memory for a double
    double* doublePtr = static_cast<double*>(allocator.allocate(sizeof(double)));
    *doublePtr = 3.14;
    std::cout << "Allocated double: " << *doublePtr << std::endl;

    // Allocate memory for a string
    char* strPtr = static_cast<char*>(allocator.allocate(6 * sizeof(char)));
    std::strcpy(strPtr, "Hello");
    std::cout << "Allocated string: " << strPtr << std::endl;

    // The allocator will automatically free the memory when it goes out of scope
    return 0;
}