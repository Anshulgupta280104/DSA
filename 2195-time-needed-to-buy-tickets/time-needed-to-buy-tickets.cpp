class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;

        // Step 1: push indices
        for (int i = 0; i < tickets.size(); i++) {
            q.push(i);
        }

        int time = 0;

        // Step 2: simulate
        while (tickets[k] != 0) {
            int idx = q.front();
            q.pop();

            tickets[idx]--;   // buy 1 ticket
            time++;

            // if still needs tickets → go back
            if (tickets[idx] > 0) {
                q.push(idx);
            }
        }

        return time;
    }
};