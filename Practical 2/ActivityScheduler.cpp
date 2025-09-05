#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start, finish, index;
};

bool activityCompare(Activity s1, Activity s2) {
    return (s1.finish < s2.finish);
}

vector<Activity> activitySelection(vector<Activity> activities) {
    sort(activities.begin(), activities.end(), activityCompare);
    vector<Activity> selected;
    selected.push_back(activities[0]);
    int lastFinish = activities[0].finish;
    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastFinish) {
            selected.push_back(activities[i]);
            lastFinish = activities[i].finish;
        }
    }
    return selected;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;
    vector<Activity> activities(n);
    cout << "Enter start and finish times of activities:\n";
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].finish;
        activities[i].index = i + 1;
    }
    vector<Activity> result = activitySelection(activities);
    cout << "\nMaximum number of non-conflicting activities: "<< result.size() << endl;
    cout << "Selected activities are:\n";
    for (int i = 0; i < result.size(); i++) {
        cout<<"Activity "<<result[i].index<<" ("<<result[i].start<<", "<<result[i].finish<<")\n";
    }
    return 0;
}
