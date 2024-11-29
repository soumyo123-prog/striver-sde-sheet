#include <bits/stdc++.h>
using namespace std;

struct Job {
  int id;        // Job Id
  int deadline;  // Deadline of job
  int profit;    // Profit if job is over before or on deadline
};

bool compare(Job a, Job b) {
  return a.profit > b.profit;  // Descending order of profit
}

vector<int> JobScheduling(Job jobs[], int n) {
  sort(jobs, jobs + n, compare);

  set<int> et;
  for (int i = 1; i <= n; i++) {
    et.insert(i);
  }

  int numJobs = 0, maxProfit = 0;

  for (int i = 0; i < n; i++) {
    int dl = jobs[i].deadline, pr = jobs[i].profit;

    auto it1 = et.find(dl);
    if (it1 != et.end()) {
      numJobs++;
      maxProfit += pr;
      et.erase(it1);
      continue;
    }

    auto it2 = et.upper_bound(dl);
    if (it2 == et.begin()) {
      continue;
    }

    numJobs++;
    maxProfit += pr;
    it2 = prev(it2);
    et.erase(it2);
  }

  return {numJobs, maxProfit};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}