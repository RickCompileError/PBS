#define CacheType unordered_map<int, NodeList*>

class NodeList {
private:
    int key;
    int val;

public:
    NodeList *post;
    NodeList *pre;

    NodeList(int key, int val) : post{nullptr}, pre{nullptr}, key{key}, val{val} {}

    NodeList() {
        NodeList(-1, -1);
    }

    void setValue(int val) {
        this -> val = val;
    }

    int getValue() {
        return val;
    }

    int getKey() {
        return key;
    }
};

class LRUCache {
private:
    CacheType cache;
    NodeList *head, *tail;
    int capacity;

public:
    LRUCache(int capacity) {
        head = new NodeList();
        tail = new NodeList();

        head -> post = tail;
        tail -> pre = head;

        this -> capacity = capacity;
    }

    void removeNode(NodeList* node) {
        node -> pre -> post = node -> post;
        node -> post -> pre = node -> pre;

        node -> pre = node -> post = nullptr;
    }

    void addNode(NodeList* node) {
        node -> pre = head;
        node -> post = head -> post;

        head -> post -> pre = node;
        head -> post = node;
    }

    void moveToHead(NodeList* node) {
        removeNode(node);
        addNode(node);
    }

    void removeFromTail(NodeList* node) {
        removeNode(node);
        delete node;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        NodeList *node = cache.find(key) -> second;

        moveToHead(node);

        return node -> getValue();
    }
    
    void put(int key, int value) {
        CacheType::const_iterator found = cache.find(key);

        if (found != cache.end()) {
            found -> second -> setValue(value);
            moveToHead(found -> second);
            return;
        }
        
        if (cache.size() == capacity) {
            cache.erase(tail -> pre -> getKey());
            removeFromTail(tail -> pre);
        }

        NodeList *node = new NodeList(key, value);
        addNode(node);
        cache[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
