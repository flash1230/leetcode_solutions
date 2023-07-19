/* https://leetcode.com/problems/lru-cache
146. LRU Cache
Medium
Linked List Map
*/
class LRUCache
{
public:
    int ll = 0;
    int k;
    struct Node
    {
        int key;
        int val;
        struct Node *prev;
        struct Node *next;
        Node(int k, int value, Node *p)
        {
            key = k;
            val = value;
            prev = p;
            next = NULL;
        }
    };
    unordered_map<int, Node *> cache;
    Node *head = new Node(0, 0, nullptr);
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
            if (iter == cache[key])
                return cache[key]->val;
            if (head == cache[key])
            {
                Node *t = head;
                head = head->next;
                head->prev = NULL;
                iter->next = t;
                t->prev = iter;
                iter = iter->next;
                return cache[key]->val;
            }
            Node *t = cache[key];
            t->prev->next = t->next;
            t->next->prev = t->prev;
            iter->next = t;
            t->prev = iter;
            t->next = NULL;
            iter = t;
        }
        return cache[key]->val;
    }

    void put(int key, int value)
    {
        if (cache.count(key))
        {
            cache[key]->val = value;
            if (iter == cache[key])
                return;
            if (head == cache[key])
            {
                Node *t = head;
                head = head->next;
                head->prev = NULL;
                iter->next = t;
                t->prev = iter;
                t->next = NULL;
                iter = t;
                return;
            }
            Node *temp = cache[key];
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            iter->next = temp;
            temp->prev = iter;
            temp->next = NULL;
            iter = temp;
            return;
        }
        else
        {
            if (ll == 0)
            {
                head->val = value;
                head->key = key;
                cache[key] = head;
                ll++;
                return;
            }
            if (ll < k)
            {
                Node *t = new Node(key, value, iter);
                iter->next = t;
                iter = t;
                ll++;
                cache[key] = t;
                return;
            }
            else
            {
                cache.erase(head->key);
                Node *t = new Node(key, value, iter);
                iter->next = t;
                iter = t;
                head = head->next;
                head->prev = nullptr;
                cache[key] = t;
            }
        }
    }
};