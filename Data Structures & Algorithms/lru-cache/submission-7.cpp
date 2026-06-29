class LRUCache {
private:
    class Node {
    public:
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

    Node* head;   // Dummy head
    Node* tail;   // Dummy tail

    // Remove a node from the list
    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Insert a node just before the dummy tail
    void insert(Node* node) {
        Node* prevNode = tail->prev;

        prevNode->next = node;
        node->prev = prevNode;

        node->next = tail;
        tail->prev = node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->value = value;

            remove(node);
            insert(node);

            return;
        }

        // Cache is full
        if (mp.size() == capacity) {
            Node* lru = head->next;

            remove(lru);
            mp.erase(lru->key);

            delete lru;
        }

        Node* newNode = new Node(key, value);

        insert(newNode);
        mp[key] = newNode;
    }
};