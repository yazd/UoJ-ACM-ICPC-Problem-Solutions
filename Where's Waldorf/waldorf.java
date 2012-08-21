import java.util.*;
import java.io.*;

public class waldorf {
  public static void main(String[] args) throws Exception {
  
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    int totalCases = Integer.parseInt(reader.readLine());
    
    while (true) {
      if (totalCases-- == 0) break;
      
      reader.readLine(); //read the empty line
      
      String line = reader.readLine();
      int cols, rows;
      String[] parts = line.split(" ");
      rows = Integer.parseInt(parts[0]);
      cols = Integer.parseInt(parts[1]);

      char[][] g = new char[rows][cols];
    
      HashMap<Character, ArrayList<Pos>> start = new HashMap<Character, ArrayList<Pos>>();
      
      for (int row = 0; row < rows; row++) {
        line = reader.readLine();
        for (int col = 0; col < cols; col++) {
          char c = Character.toLowerCase(line.charAt(col));
          g[row][col] = c;
          if (start.containsKey(c)) {
            start.get(c).add(new Pos(row, col));
          } else {
            ArrayList<Pos> a = new ArrayList<Pos>();
            a.add(new Pos(row, col));
            start.put(c, a);
          }
        }
      }

      int words = Integer.parseInt(reader.readLine());
      
      NextWord: for (int i = 0; i < words; i++) {
        String word = reader.readLine().toLowerCase();
        
        while (true) {
          
          ArrayList<Pos> starts = start.get(word.charAt(0));
          for (Pos s : starts) {
            for (int tries = 0; tries < 8; tries++) {

              String foundWord = getWord(g, cols, rows, s, tries, word.length())  ;
              //System.out.println(foundWord);
              if (foundWord.compareTo(word) == 0) {
                System.out.println((s.row + 1) + " " + (s.col + 1));
                continue NextWord;
              }
            }
          }
        }
      }
    
      if (totalCases > 0) System.out.println();

    }
  
  }
  
  static String getWord(char[][] grid, int cols, int rows, Pos start, int direction, int len) {
    
    //direction = {0: left to right, 1: right to left,
    //         2: top to down,   3: down to top,
    //         4: to down right, 5: to down left,
    //             6: to up right,   7: to up left
    
    StringBuilder out = new StringBuilder();
    int moves = 0;
    
    if (direction == 0) {
      for (int col = start.col; (col < cols) && (moves < len); col++) {
        moves++;
        out.append(grid[start.row][col]);
      }
    } else if (direction == 1) {
      for (int col = start.col; (col >= 0) && (moves < len); col--) {
        moves++;
        out.append(grid[start.row][col]);
      }
    } else if (direction == 2) {
      for (int row = start.row; (row < rows) && (moves < len); row++) {
        moves++;
        out.append(grid[row][start.col]);
      }
    } else if (direction == 3) {
      for (int row = start.row; (row >= 0) && (moves < len); row--) {
        moves++;
        out.append(grid[row][start.col]);
      }
    } else if (direction == 4) {
      for (int col = start.col, row = start.row; (col < cols) && (row < rows) && (moves < len); col++, row++) {
        moves++;
        out.append(grid[row][col]);
      }
    } else if (direction == 5) {
      for (int col = start.col, row = start.row; (col >= 0) && (row < rows) && (moves < len); col--, row++) {
        moves++;
        out.append(grid[row][col]);
      }
    } else if (direction == 6) {
      for (int col = start.col, row = start.row; (col < cols) && (row >= 0) && (moves < len); col++, row--) {
        moves++;
        out.append(grid[row][col]);
      }
    } else if (direction == 7) {
      for (int col = start.col, row = start.row; (col >= 0) && (row >= 0) && (moves < len); col--, row--) {
        moves++;
        out.append(grid[row][col]);
      }
    }
    
    return out.toString();

  }

  static class Pos {
    int row, col;
    
    Pos (int row, int col) {
      this.row = row;
      this.col = col;
    }
  }

}
