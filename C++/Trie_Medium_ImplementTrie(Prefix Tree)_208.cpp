struct Node
{
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node)
    {
        links[ch - 'a'] = node;
    }
    
    Node* get(char ch)
    {
        return links[ch - 'a'];
    }

    bool setEnd()
    {
        flag = true;
        return flag;
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie {

private: Node* root;

public:

    Trie()
    {
        root = new Node();
    }
    
    void insert(string prefix)
    {
        Node* node = root;
        for(int i = 0; i < prefix.size(); i++)
        {
            if(!node -> containsKey(prefix[i]))
            {
                node -> put(prefix[i], new Node());
            }

            //Moves to the reference trie
            node = node -> get(prefix[i]);
        }    

        node -> setEnd();
    }
    
    bool search(string prefix)
    {
        Node* node = root;
        for(int i = 0; i < prefix.length(); i++)
        {
            if(!node -> containsKey(prefix[i]))
            {
                return false;
            }
            node = node -> get(prefix[i]);
        }
        return node -> isEnd();
    }
    
    bool startsWith(string prefix)
    {
        Node* node = root;
        for(int i = 0; i < prefix.length(); i++)
        {
            if(!node -> containsKey(prefix[i]))
            {
                return false;
            }
            node = node -> get(prefix[i]);
        }    

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(prefix);
 * bool param_2 = obj->search(prefix);
 * bool param_3 = obj->startsWith(prefix);
 */