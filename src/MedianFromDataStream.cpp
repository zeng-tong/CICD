// 
// Created by tong zeng on 2018/7/5 9:07 AM.
//
#include "commonHeader"

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() : left(sets.end()), right(sets.end()){
    }

    void addNum(int num) {
        if (sets.empty()) {
            sets.insert(num);
            left = right = sets.begin();
            return;
        }
        sets.insert(num);
        if (sets.size() % 2 == 1) { //odd
            if (num >= *right) left = right;
            else left = --right; //log(n)
        } else {
            if (num >= *right) ++right;
            else --left;
        }
    }

    double findMedian() {
        return static_cast<double > (*left + *right) / 2;
    }
    multiset<int> getSets(){
        return sets;
    }

private:
    multiset<int> sets;
    multiset<int>::iterator left;
    multiset<int>::iterator right;
};

int main() {
    // 1,2,find,3,find,4,find,5,find
    string line;
    while(getline(cin, line)) {
        MedianFinder medianFinder;
        istringstream is(line);
        string command;
        while(getline(is, command, ',')) {
            if (command == "find") {
//                auto sets = medianFinder.getSets();
//                for(auto i : sets) cout << i << " ";
//                cout << endl;
                cout << "Find: " << medianFinder.findMedian() << endl;
            } else {
                medianFinder.addNum(stoi(command));
            }
        }
    }
    return 0;
}