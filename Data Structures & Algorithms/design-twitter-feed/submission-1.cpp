class Twitter {
   public:
    int time = 0;

    struct ListNode {
        int tweetId;
        int times;
        ListNode* next;

        ListNode(int id, int t) {
            tweetId = id;
            times = t;
            next = nullptr;
        }
    };

    // These are MEMBER VARIABLES, not constructor locals
    unordered_map<int, ListNode*> tweets;
    unordered_map<int, unordered_set<int>> following;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        ListNode* temp = new ListNode(tweetId, time);

        if (!tweets[userId]) {
            tweets[userId] = temp;
        } else {
            temp->next = tweets[userId];
            tweets[userId] = temp;
        }

        time++;
    }
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) { return a->times < b->times; }
    };

    
    vector<int> getNewsFeed(int userId) {
    vector<int> ans;

    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

    // Push user's own tweets
    if (tweets[userId] != nullptr)
        pq.push(tweets[userId]);

    // Push the head of each followed user's tweets
    for (int followee : following[userId]) {
        if (tweets[followee] != nullptr)
            pq.push(tweets[followee]);
    }

    while (!pq.empty() && ans.size() < 10) {

        ListNode* current = pq.top();
        pq.pop();

        ans.push_back(current->tweetId);

        if (current->next != nullptr)
            pq.push(current->next);
    }

    return ans;
}

    void follow(int followerId, int followeeId) { 
    
    if (followerId == followeeId) return;
    following[followerId].insert(followeeId);
}

    void unfollow(int followerId, int followeeId) {following[followerId].erase(followeeId); }
};