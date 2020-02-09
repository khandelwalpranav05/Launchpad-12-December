class MedianFinder {
public:
    /** initialize your data structure here. */

    priority_queue<int, vector<int> > maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;

    MedianFinder() {

    }

    void addNum(int num) {
        if (maxHeap.empty() or maxHeap.top() > num) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (minHeap.size() + 1 < maxHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (maxHeap.size() + 1 < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {

        if (minHeap.size() == maxHeap.size()) {
            if (maxHeap.empty()) {
                return 0;
            } else {
                return (maxHeap.top() + minHeap.top()) / 2.0;
            }
        } else {
            return minHeap.size() > maxHeap.size() ? minHeap.top() : maxHeap.top();
        }

    }
};