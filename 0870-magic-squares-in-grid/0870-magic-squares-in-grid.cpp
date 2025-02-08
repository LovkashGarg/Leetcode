class Solution {
public:
    int ans = 0;

    void solve(int i, int j, int m, int n, vector<vector<int>>& grid,
               vector<vector<int>>& visited) {

        visited[i][j] = 1;

        set<int> s;
        bool flag = true;

        if (i + 3 > m || j + 3 > n) {
            flag = false;
        }

        if (flag ==true) {
            // check a grid starting from here
            for (int k = i; k < i + 3 ; k++) {
                for (int l = j; l < j + 3 ; l++) {
                    if(grid[k][l] >=10 || grid[k][l]==0){
                        flag=false;
                        break;
                    }

                    if (s.find(grid[k][l]) != s.end()) {
                        flag = false;
                        break;
                    }

                    s.insert(grid[k][l]);
                }

                if (flag == false) {
                    break;
                }
            }

            if (flag == true) {

                vector<int> row(m, 0);
                vector<int> col(n, 0);
 int t=0;
                for (int k = i; k < i + 3 && k < m; k++) {
                    int sum = 0;
                    for (int l = j; l < j + 3 && l < n; l++) {
                        sum += grid[k][l];
                    }
                    row[t] = sum;
                    t++;
                }
               t=0;
                for (int l = j; l < j + 3 && l < n; l++) {
                    int sum = 0;
                    for (int k = i; k < i + 3 && k < m; k++) {
                        sum += grid[k][l];
                    }
                    col[t] = sum;
                    t++;
                }

                int sum = row[0];
                for (int c = 0; c < 3; c++) {
                    if (sum != row[c]) {
                        flag = false;
                        break;
                    }
                }
                sum = col[0];
                for (int c = 0; c < 3; c++) {
                    if (sum != col[c] || col[c] != row[c]) {
                        flag = false;
                        break;
                    }
                }
                
                int sumd1=0;
                // check diagonal 
                for(int k=0;k<3 ;k++){
                 sumd1+=grid[i+k][j+k];
                }
                if(sumd1!=row[0]){
                    flag=false;
                }
int sumd2=0;
                for(int k=0;k<3;k++){
                    cout<< i+2-k<< j+k<<endl;
                 sumd2+=grid[i+2-k][j+k];
                }
                
                cout<< sumd2<<endl;
                if(sumd2!=row[0]   ){
                    flag=false;
                }

                if (flag == true) {
                    ans = ans + 1;
                }


            }
        }

        // traverse all four possiblity
        vector<int> dirrow = {1, 0, -1, 0};
        vector<int> dircol = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {

            int newrow = i + dirrow[k];
            int newcol = j + dircol[k];

            if (newrow >= 0 && newrow < m && newcol >= 0 && newcol < n &&
                visited[newrow][newcol] == 0) {
                solve(newrow, newcol, m, n, grid, visited);
            }
        }
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m<3 || n<3){
        return 0;
        }

        // make a gird with all
        vector<vector<int>> visited(m, vector<int>(n, 0));
        solve(0, 0, m, n, grid, visited);
        return ans;
    }
};