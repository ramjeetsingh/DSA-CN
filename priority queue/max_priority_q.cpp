#include <vector>
#include <iostream>
using namespace std;

class maxPriorityQueue {
    vector<int> pq;         //complete binary tree

    public:

    maxPriorityQueue() {

    }

    bool isEmpty() {
        if (pq.size() == 0) {
            return true;
        } else {
            return false;
        }
    }

    int getSize() {
        return pq.size();
    }

    int getMax() {
        if (pq.size() != 0) {
            return pq[0];
        }
        return INT_MIN;
    }


    void insert(int data) {
        pq.push_back(data);
        int childInd = pq.size()-1;

        while (childInd > 0) {
            int parentInd = (childInd-1)/2;

            if (pq[childInd] > pq[parentInd]) {
                int temp = pq[childInd];
                pq[childInd] = pq[parentInd];
                pq[parentInd] = temp;
            } else {
                break;
            }

            childInd = parentInd;
        }
    }


    int removeMax() {
        if (pq.size() == 0) {
            return INT_MIN;
        }
        if (pq.size() == 1) {
            pq.pop_back();
        }

        int ans = pq[0];

        int lastInd = pq.size()-1;
        int element = pq[lastInd];

        pq[0] = element;
        pq.pop_back();

        //down-heapify:

        int parent_ind = 0;
        int left_child_ind = 2*parent_ind + 1;
        int right_child_ind = 2*parent_ind + 2;

        while (left_child_ind < pq.size()) {
            int minInd = parent_ind;

            if (pq[left_child_ind] > pq[minInd]) {
                minInd = left_child_ind;
            }

            if (right_child_ind < pq.size() && pq[right_child_ind] > pq[minInd]) {
                minInd = right_child_ind;
            }

            if (minInd == parent_ind) {
                break;
            }

            int temp = pq[minInd];
            pq[minInd] = pq[parent_ind];
            pq[parent_ind] = temp;

            parent_ind = minInd;
            left_child_ind = 2*parent_ind + 1;
            right_child_ind = 2*parent_ind + 2;

        }

        return ans;
    }

};


int main() {
    maxPriorityQueue q;

    q.insert(2);
    q.insert(5);
    q.insert(3);
    q.insert(9);
    q.insert(10);
    q.insert(3);
    q.insert(8);

    cout << q.getSize() << endl;
    cout << q.getMax() << endl;

    q.removeMax();
    cout << q.getMax() << endl;

    q.removeMax();
    cout << q.getMax() << endl;

    q.removeMax();
    cout << q.getMax() << endl;

}