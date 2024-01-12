
/**
 * @ClassName: leet79
 * @Description:
 * @Author: wzt
 * @Create: 2024-01-12 17:43
 **/

public class leet79 {
    public static int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    public static boolean dp(char[][] board, String word, int i, int j, int index, boolean[][] visited) {
        if (visited[i][j] || board[i][j] != word.charAt(index)) return false;
        if (index == word.length() - 1) return true;
        visited[i][j] = true;
        int r = board.length, c = board[0].length;
        for (int[] dir : dirs) {
            if (i + dir[0] < r && i + dir[0] >= 0 && j + dir[1] < c && j + dir[1] >= 0) {
                if (dp(board, word, i + dir[0], j + dir[1], index + 1, visited)) return true;
            }
        }
        visited[i][j] = false;
        return false;
    }

    public static boolean exist(char[][] board, String word) {
        int r = board.length;
        int c = board[0].length;
        boolean[][] visited = new boolean[r][c]; // 创建一个布尔型二维数组用于记录已访问位置
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (dp(board, word, i, j, 0, visited)) return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        char[][] board = {
                {'C', 'A', 'A'},
                {'A', 'A', 'A'},
                {'B', 'C', 'D'}
        };

        String word = "AAB";
        exist(board, word);
    }
}
