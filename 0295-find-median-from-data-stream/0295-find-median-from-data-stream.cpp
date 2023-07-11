class MedianFinder
{
    public:

      std::priority_queue<int> maxpq;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minpq;

    MedianFinder() {}

    void addNum(int num) {
        int n1 = maxpq.size(), n2 = minpq.size();

        if (n1 == n2) {
            if (!minpq.empty() && num > minpq.top()) {
                int a = minpq.top();
                minpq.pop();
                maxpq.push(a);
                minpq.push(num);
            } else {
                maxpq.push(num);
            }
        } else {
            if (!maxpq.empty() && num < maxpq.top()) {
                int b = maxpq.top();
                maxpq.pop();
                minpq.push(b);
                maxpq.push(num);
            } else {
                minpq.push(num);
            }
        }
    }

    double findMedian() {
        int n1 = maxpq.size(), n2 = minpq.size();

        if (n1 == n2) {
            return (maxpq.top() + minpq.top()) / 2.0;
        } else {
            return maxpq.top();
        }
    }
};

/**
 *Your MedianFinder object will be instantiated and called as such:
 *MedianFinder* obj = new MedianFinder();
 *obj->addNum(num);
 *double param_2 = obj->findMedian();
 */