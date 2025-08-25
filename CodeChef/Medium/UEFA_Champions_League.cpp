#include <bits/stdc++.h>
using namespace std;

struct Team {
    string name;
    int points = 0;
    int goalsScored = 0;
    int goalsAgainst = 0;

    int goalDiff() const {
        return goalsScored - goalsAgainst;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        unordered_map<string, Team> teams;

        for (int i = 0; i < 12; i++) {
            string home, away, vs;
            int hg, ag;
            cin >> home >> hg >> vs >> ag >> away;

            // Ensure both teams exist
            if (!teams.count(home)) teams[home] = {home};
            if (!teams.count(away)) teams[away] = {away};

            // Update goals
            teams[home].goalsScored += hg;
            teams[home].goalsAgainst += ag;
            teams[away].goalsScored += ag;
            teams[away].goalsAgainst += hg;

            // Update points
            if (hg > ag) {
                teams[home].points += 3;
            } else if (hg < ag) {
                teams[away].points += 3;
            } else {
                teams[home].points += 1;
                teams[away].points += 1;
            }
        }

        // Collect all teams
        vector<Team> v;
        for (auto &kv : teams) v.push_back(kv.second);

        // Sort by points, then goal difference
        sort(v.begin(), v.end(), [](const Team &a, const Team &b) {
            if (a.points != b.points) return a.points > b.points;
            return a.goalDiff() > b.goalDiff();
        });

        cout << v[0].name << " " << v[1].name << "\n";
    }

    return 0;
}
