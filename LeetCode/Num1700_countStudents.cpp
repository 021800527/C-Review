#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int num = 0;
        while (!sandwiches.empty()&& num != students.size()) {
            num = 0;
            if (sandwiches.front() == students.front()) {
                sandwiches.erase(sandwiches.begin());
                students.erase(students.begin());
            } else {
                students.push_back(students.front());
                students.erase(students.begin());
                num++;
            }
        }
        return students.size();
    }
};