class SkipList
{
public:
    SkipList(int level_max = 32) : max_level(level_max)
    {
        head = new SkipListNode(INT32_MIN);
        head->next = new SkipListNode(INT32_MAX);
        auto head_ = head;
        while (level < level_max - 1)
        {
            head_->down = new SkipListNode(INT32_MIN);
            head_ = head_->down;
            head_->next = new SkipListNode(INT32_MAX);
            head_->down = nullptr;
            ++level;
        }
    }

    void insert(int value)
    {
        std::vector<SkipListNode*> elem_before_val;
        auto Node = head;

        while (Node)
        {
            while (Node->next->value < value) {Node = Node->next;}
            elem_before_val.push_back(Node);
            if (Node->down == nullptr) {break;}
            Node = Node->down;
        }

        level = 0;

        auto node = new SkipListNode(value);
        while (level == 0 || random())
        {
            auto *This = new SkipListNode(value);
            if (level > 0)
            {
                This->down = node;
            }
            SkipListNode *Node_before_elem = elem_before_val[max_level - level - 1];

            This->next = Node_before_elem->next;
            Node_before_elem->next = This;
            node = This;

            ++level;
        }


    }

    void print() const
    {
        auto head_ = head;

        while (head_->down)
        {
            head_ = head_->down;
        }

        for (auto i = head_; i != nullptr; i = i->next)
        {
            std::cout << i->value << ' ';
        }
        std::cout << std::endl;
    }

    ~SkipList()
    {
        SkipListNode *head_ = head;
        while (head_)
        {
            SkipListNode *next = head_->next;
            delete head_;
            head_ = next;
        }
    }

private:
    struct SkipListNode
    {
        int value;
        SkipListNode *next;
        SkipListNode *down;
        SkipListNode(int value) : value(value), next(nullptr), down(nullptr) {}
    };

    bool random()
    {
        std::random_device rnd;
        std::mt19937 mk(rnd());
        return ((mk() % 2) && (level < max_level));
    }

    int level = 0;
    int max_level;
    SkipListNode *head;
};