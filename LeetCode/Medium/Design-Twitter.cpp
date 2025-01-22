// Time: O(n) by heapify, Space: (N*T + N*F), N is number of users, T is maxmium Tweets, F is maximum followees
#define Tweet pair<int, int>

class TweetComparator {
public:
    bool operator() (const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
};

class Twitter {
private:
    int counter;
    unordered_map<int, vector<Tweet>> tweetList;
    unordered_map<int, unordered_set<int>> followList;

public:
    Twitter() {
        counter = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetList[userId].push_back({counter++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>, vector<vector<int>>, TweetComparator> feeds;

        followList[userId].insert(userId);

        for (int followee: followList[userId]) {
            vector<Tweet>& tweets = tweetList[followee];
            if (tweets.empty()) {
                continue;
            }

            int lastIdx = tweets.size() - 1;
            feeds.push({tweets[lastIdx].first, tweets[lastIdx].second, followee, lastIdx});
        }

        vector<int> res;
        while (res.size() < 10 && !feeds.empty()) {
            vector<int> feed = feeds.top(); feeds.pop();
            int tweetId = feed[1];
            int followee = feed[2];
            int lastIdx = feed[3] - 1;

            res.push_back(tweetId);

            if (lastIdx < 0) {
                continue;
            }
            vector<Tweet>& tweets = tweetList[followee];
            feeds.push({tweets[lastIdx].first, tweets[lastIdx].second, followee, lastIdx});
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
