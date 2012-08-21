import java.util.*;
import java.io.*;

class judge {
  public static void main(String[] args) throws Exception {

    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    int run = 0;

    while (true) {

      run++;
      String line = reader.readLine();
      int n = Integer.parseInt(line);

      if (n == 0) break;

      StringBuilder goodLines = new StringBuilder();
      StringBuilder goodNums = new StringBuilder();

      buildCom(reader, n, goodLines, goodNums);

      int m = Integer.parseInt(reader.readLine());
      StringBuilder inLines = new StringBuilder();
      StringBuilder inNums = new StringBuilder();

      buildCom(reader, m, inLines, inNums);

      System.out.print("Run #");
      System.out.print(run);
      System.out.print(": ");

      if (goodLines.toString().compareTo(inLines.toString()) == 0) {
        System.out.println("Accepted");
      } else if (goodNums.toString().compareTo(inNums.toString()) == 0) {
        System.out.println("Presentation Error");
      } else {
        System.out.println("Wrong Answer");
      }

    }

  }

  static void buildCom(BufferedReader reader, int numberOfLines, StringBuilder lines, StringBuilder nums) throws Exception {

    String line;

    for (int i = 0; i < numberOfLines; i++) {
        
      line = reader.readLine();
      lines.append(line + '\n');
        
      for (int j = 0; j < line.length(); j++) {
        if (Character.isDigit(line.charAt(j))) {
          nums.append(line.charAt(j));
        }
      }

    }

    return;

  }

}