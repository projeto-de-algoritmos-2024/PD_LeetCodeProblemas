#include <vector>
#include <algorithm>
using namespace std;

struct Job
{
    int startTime;
    int endTime;
    int profit;
};

class Solution {
public:

    static bool compareByEndTime(Job &a, Job &b) {
        return a.endTime < b.endTime;
    }

    void computeP(vector<int> &p, vector<Job> &jobs, int n) {
        for (int i = 0; i < n; i++) {
            p[i] = 0;

            for (int j = i - 1; j >= 0; j--) {
                if (jobs[i].startTime >= jobs[j].endTime) {
                    p[i] = j;
                    break;
                }
            }
        }   
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        std::vector<Job> jobs(n);

        for (int i = 0; i < n; i++)
            jobs[i] = {startTime[i], endTime[i], profit[i]};

        std::sort(jobs.begin(), jobs.end(), compareByEndTime);
        
        vector<int> p(n);

        computeP(p, jobs, n);
    }
};