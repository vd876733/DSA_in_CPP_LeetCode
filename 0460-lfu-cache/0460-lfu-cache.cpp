class LFUCache {
private:

    struct Node {
        int key;
        int value;
        int freq;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
        }
    };

    int capacity;
    int minFreq;

    // key -> node
    unordered_map<int, Node*> keyMap;

    // frequency -> LRU list
    unordered_map<int, list<Node*>> freqMap;

    // Move a node from freq to freq + 1
    void increaseFreq(Node* node) {

        int oldFreq = node->freq;

        // Remove from old frequency list
        freqMap[oldFreq].remove(node);

        // If this was the minimum frequency
        if (oldFreq == minFreq &&
            freqMap[oldFreq].empty()) {

            minFreq++;
        }

        // Increase frequency
        node->freq++;

        // Add to new frequency list
        freqMap[node->freq].push_front(node);
    }

public:

    LFUCache(int capacity) {

        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {

        // Key doesn't exist
        if (keyMap.find(key) == keyMap.end()) {
            return -1;
        }

        Node* node = keyMap[key];

        // Increase frequency
        increaseFreq(node);

        return node->value;
    }

    void put(int key, int value) {

        // Capacity is zero
        if (capacity == 0) {
            return;
        }

        // Key already exists
        if (keyMap.find(key) != keyMap.end()) {

            Node* node = keyMap[key];

            node->value = value;

            // Using put also increases frequency
            increaseFreq(node);

            return;
        }

        // Cache is full
        if (keyMap.size() == capacity) {

            // Get least frequently used list
            auto& lruList = freqMap[minFreq];

            // Least recently used node
            Node* lru = lruList.back();

            // Remove from list
            lruList.pop_back();

            // Remove from map
            keyMap.erase(lru->key);

            delete lru;
        }

        // Create new node
        Node* node = new Node(key, value);

        // New node has frequency 1
        keyMap[key] = node;

        freqMap[1].push_front(node);

        // New node establishes minimum frequency
        minFreq = 1;
    }
};