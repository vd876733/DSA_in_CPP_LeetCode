class LRUCache {
private:

    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;

    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    // Remove a node from the list
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Add node right after head
    void add(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:

    LRUCache(int capacity) {

        this->capacity = capacity;

        // Dummy nodes
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        // Move to front because it was recently used
        remove(node);
        add(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->value = value;

            // Move to front
            remove(node);
            add(node);

            return;
        }

        // Create new node
        Node* node = new Node(key, value);

        mp[key] = node;
        add(node);

        // Capacity exceeded
        if (mp.size() > capacity) {

            Node* lru = tail->prev;

            mp.erase(lru->key);

            remove(lru);

            delete lru;
        }
    }
};