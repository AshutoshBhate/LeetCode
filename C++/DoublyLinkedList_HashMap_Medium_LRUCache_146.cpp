class LRUCache {
private:
    struct Node
    {
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v)
        {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int LL_capacity;
    unordered_map<int, Node*> myMap;

    void addNode(Node* newNode)
    {
        Node* nextNode = dummyHead -> next;
        dummyHead -> next = newNode;
        newNode -> prev = dummyHead;
        nextNode -> prev = newNode;
        newNode -> next = nextNode;
    }

    void removeNode(Node* delNode)
    {
        Node* prevNode = delNode -> prev;
        Node* nextNode = delNode -> next;
        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
    }

public:
    Node* dummyHead = new Node(-1, -1);
    Node* dummyTail = new Node(-1, -1);

    LRUCache(int capacity) 
    {
        LL_capacity = capacity;

        dummyHead -> next = dummyTail;
        dummyTail -> prev = dummyHead;
    }
    
    int get(int key) 
    {
        if(myMap.find(key) != myMap.end())
        {
            Node* toGet = myMap[key];
            removeNode(toGet);
            addNode(toGet);
            return toGet -> value;
        }
        else
        {
            return -1;
        }
    }
    
    void put(int key, int value) 
    {
        if(myMap.find(key) != myMap.end())
        {
            Node* changeNode = myMap[key];
            changeNode -> value = value;
            removeNode(changeNode);
            addNode(changeNode);
        }
        else
        {
            if(myMap.size() >= LL_capacity)
            {
                // Node* eraseNode = dummyTail -> prev;
                // Node* bufferNode = eraseNode -> prev;
                // bufferNode -> next = dummyTail;
                // dummyTail -> prev = bufferNode;
                //For the non-commented code, which is an improvisation, we store the 
                //node in a pointer for lated erasure
                Node* eraseNode = dummyTail -> prev;
                removeNode(eraseNode);
                //myMap.erase(eraseNode -> key);
                myMap.erase(eraseNode -> key);
                //delete eraseNode;
                delete eraseNode;
            }
            Node* insertNode = new Node(key, value);
            addNode(insertNode);
            myMap[key] = insertNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */