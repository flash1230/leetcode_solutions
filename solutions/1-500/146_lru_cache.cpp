class LRUCache
{
public:
    int ll = 0;
    int k;
    unordered_map<int, int> cache;
    struct Node
    {
        int val;
        struct Node *next;
        Node(int value)
        {
            val = value;
            next = NULL;
        }
    };
    Node *head = new Node(0);
    Node *iter;

    LRUCache(int capacity)
    {
        k = capacity;
        iter = head;
    }

    int get(int key)
    {
        if (!cache.count(key))
            return -1;
        else
        {
            if (iter->val == key)
                return cache[key];
            if (head->val == key)
            {
                Node *t = head;
                head = head->next;
                iter->next = t;
                iter = iter->next;
                return cache[key];
            }
            Node *temp = head;
            while (temp->next->val != key)
                temp = temp->next;
            iter->next = temp->next;
            temp->next = temp->next->next;
            iter = iter->next;
        }
        return cache[key];
    }

    void put(int key, int value)
    {
        if (cache.count(key))
        {
            cache[key] = value;
            if (iter->val == key)
            {
                return;
            }
            if (head->val == key)
            {
                Node *t = head;
                head = head->next;
                iter->next = t;
                iter = iter->next;
                return;
            }
            Node *temp = head;
            while (temp->next->val != key)
                temp = temp->next;
            iter->next = temp->next;
            temp->next = temp->next->next;
            iter = iter->next;
            return;
        }
        else
        {
            if (ll == 0)
            {
                head->val = key;
                cache[key] = value;
                ll++;
                return;
            }
            if (ll < k)
            {
                Node *t = new Node(key);
                iter->next = t;
                iter = iter->next;
                ll++;
                cache[key] = value;
                return;
            }
            else
            {
                cache.erase(head->val);
                Node *t = new Node(key);
                iter->next = t;
                iter = iter->next;
                head = head->next;
                cache[key] = value;
            }
        }
    }
};