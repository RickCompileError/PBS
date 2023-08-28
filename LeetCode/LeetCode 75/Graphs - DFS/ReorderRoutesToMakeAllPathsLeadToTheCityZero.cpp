// Time: O(n), Space: O(n)
// unordered_map version, 666ms
class Solution {
public:

    void redirect(unordered_map<int, vector<int>>& direction, unordered_map<int, bool>& visited, int& ans, int city = 0) {
        visited[city] = true;
        for (int i: direction[city]) {
            if (!visited[i]) {
                if (i >= 0) ans++;
                redirect(direction, visited, ans, abs(i));
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> direction;
        unordered_map<int, bool> visited;
        int ans = 0;
        for (vector<int> connection: connections) {
            direction[connection[0]].push_back(connection[1]);
            direction[connection[1]].push_back(-connection[0]);
        }
        redirect(direction, visited, ans);
        return ans;
    }
};

// vector version, 242ms
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        //for every city store the adjacent city along with direction 
        //to store the direction we use positive indicating a road from a to b for a
        //we use negative indicating there is a road from b to a for a
        
        vector<vector<int>> adjCities(n);
        vector<bool> visited(n,false);
        for(int i=0;i<connections.size();i++){
            int city1=connections[i][0];
            int city2=connections[i][1];
            adjCities[city1].push_back(city2);
            adjCities[city2].push_back(-city1);
        }
        
        //start dfs from city  0 
        //when ever you found a positive then it need to be reversed
        int count=0;
        reorderPaths(0,adjCities,count,visited);
        return count;

    }


    void reorderPaths(int currCity,vector<vector<int>>& adjCities,int& count,vector<bool>& visited){
        visited[currCity]=true;
        for(auto city:adjCities[currCity]){
            if(!visited[abs(city)]){
                if(city>0) //reorder the path 
                    count++;
                reorderPaths(abs(city),adjCities,count,visited);
            }
        }
    }
};