// Globals
int gcapacity;
unordered_map<int, int> gmap;
// Fresh key at front and stale at tail
deque<int> glru_q;

LRUCache::LRUCache(int capacity) {
    gcapacity = capacity;
    gmap.clear();
    glru_q.clear();
}

int LRUCache::get(int key) {
    if (gmap.find(key) == gmap.end()) {
        return -1;
    }

    // Refresh the key and move this key to front of the glru_q
    auto it = find(glru_q.begin(), glru_q.end(), key);
    assert(it != glru_q.end());
    glru_q.erase(it);
    glru_q.push_front(key);

    return gmap[key];
}

void LRUCache::set(int key, int value) {
    // Make sure we refresh the access to key
    // Its possible we are just overwriting a key
    if (LRUCache::get(key) != -1) {
        gmap[key] = value;
        return;
    }
    
    // Reached capacity, we should eject the oldest
    if (glru_q.size() == gcapacity) { 
        gmap.erase(glru_q.back());
        glru_q.pop_back();
    }

    // Add to front of the Q
    gmap[key] = value;
    glru_q.push_front(key);
}
