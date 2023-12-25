#include<string>
#include<unordered_set>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> dir = {{1,0}, {-1, 0}, {0, 1}, {0, -1}}; 
bool dfs(vector<vector<char>>& board, string word, string cur, int i, int j){
    if(cur.size() == word.size()){
        if(cur == word)return true;
        return false;
    }
    

}
bool exist(vector<vector<char>>& board, string word) {
    for(int i = 0; i < board.size(); ++i){
        for(int j = 0; j < board[0].size(); ++j){
            if(board[i][j] == word[0]){
                dfs(board, word, to_string(board[i][j]), i, j);
                
            }
        }
    }
}