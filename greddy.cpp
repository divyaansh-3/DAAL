#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;

    cout << "Enter number of activities: ";
    cin >> n;

    vector<Activity> activities(n);

    cout << "Enter start and finish time of each activity:\n";

    for (int i = 0; i < n; i++) {
        cout << "Activity " << i + 1 << ": ";
        cin >> activities[i].start >> activities[i].finish;
    }

    sort(activities.begin(), activities.end(), compare);

    cout << "\nActivities sorted according to finishing time:\n";

    for (int i = 0; i < n; i++) {
        cout << "Activity " << i + 1
             << " : Start = " << activities[i].start
             << ", Finish = " << activities[i].finish << endl;
    }

    cout << "\nSelected compatible activities:\n";

    int count = 1;
    int lastFinish = activities[0].finish;

    cout << "Activity with Start = "
         << activities[0].start
         << ", Finish = "
         << activities[0].finish << endl;

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastFinish) {
            cout << "Activity with Start = "
                 << activities[i].start
                 << ", Finish = "
                 << activities[i].finish << endl;

            lastFinish = activities[i].finish;
            count++;
        }
    }

    cout << "\nMaximum number of activities selected = "
         << count << endl;

    return 0;
}