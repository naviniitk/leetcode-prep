class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        char choices[] = {'A', 'C', 'G', 'T'};
        queue<string> q;
        q.push(startGene);
        set<string> seen;
        seen.insert(startGene);

        int steps = 0;

        while (!q.empty()) {
            int nodesInQueue = q.size();

            for (int j = 0; j < nodesInQueue; j++) {
                string node = q.front();
                q.pop();

                if (node == endGene)
                    return steps;

                for (char choice: choices) {
                    for (int i = 0; i < node.size(); i++) {
                        string neighbor = node.substr(0, i) + choice + node.substr(i + 1);

                        if (seen.find(neighbor) == seen.end() && find(bank.begin(), bank.end(), neighbor) != bank.end()) {
                            q.push(neighbor);
                            seen.insert(neighbor);
                        }
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};
