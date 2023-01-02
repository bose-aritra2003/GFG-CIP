#include <iostream>
#include <vector>

using namespace std;

// Minimum Coins to make a change
int minCoins(int n) {
    /**
     * Time Complexity: O(n)
     */
    vector<int> coins = {5, 10, 2, 1};
    sort(coins.begin(), coins.end(), greater<int>());
    int count = 0;
    for (int &coin : coins) {
        count += n / coin;
        n = n % coin;
    }
    return count;
}

// Maximum Activities done by a single machine
bool myCmp1(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
}
int maxActivities(vector<pair<int, int>> &activities) {
    /**
     * Time Complexity: O(n log n)
     */
    int n = activities.size();
    sort(activities.begin(), activities.end(), myCmp1);
    int count = 1;
    int finish = activities[0].second;
    for (int i = 1; i < n; i++) {
        if (activities[i].first >= finish) {
            count++;
            finish = activities[i].second;
        }
    }
    return count;
}

// Fractional KnapSack
struct Item {
    int value;
    int weight;
};
bool myCmp2(Item &a, Item &b) {
    double r1 = (double) a.value / a.weight;
    double r2 = (double) b.value / b.weight;
    return r1 > r2;
}
double fractionalKnapSack(vector<Item> &items, int capacity) {
    /**
     * Time Complexity: O(n log n)
     */
    sort(items.begin(), items.end(), myCmp2);
    double value = 0;
    for(Item &item : items) {
        if (capacity >= item.weight) {
            capacity -= item.weight;
            value += item.value;
        }
        else {
            value += (double) item.value / item.weight * capacity;
            break;
        }
    }
    return value;
}

// Job Sequencing
struct Job {
    char id;
    int deadline;
    int profit;
};
bool myCmp3(Job &a, Job &b) {
    return a.profit > b.profit;
}
vector<char> jobSequencing(vector<Job> &jobs) {
    /**
     * Time Complexity: O(n log n)
     */
    sort(jobs.begin(), jobs.end(), myCmp3);
    int n = jobs.size();
    int maxDeadline = 0;
    for (Job &job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }
    vector<bool> slots(maxDeadline, false);
    vector<char> result;
    for (Job &job : jobs) {
        for (int i = job.deadline - 1; i >= 0; i--) {
            if (!slots[i]) {
                slots[i] = true;
                result.push_back(job.id);
                break;
            }
        }
    }
    return result;
}

int main() {

    return 0;
}