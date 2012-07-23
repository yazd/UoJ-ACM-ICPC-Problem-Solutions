import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

class ballots {
  public static void main(String[] args) throws Exception {

    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    String line = reader.readLine().trim();
    int testCases = Integer.parseInt(line);

    line = reader.readLine(); //read the empty line

    while (testCases-- > 0) {

      line = reader.readLine().trim();
      if (line.length() == 0) {
        testCases++;
        continue;
      }

      int n = Integer.parseInt(line);
      String[] names = new String[n];

      for (int i = 0; i < n; i++)
        names[i] = reader.readLine().trim();

      ArrayList<Integer[]> results = new ArrayList<Integer[]>();

      while (true) {

        line = reader.readLine();
        if (line == null || line.length() == 0) break;

        line = line.trim();
        Integer[] ballot = new Integer[n];

        String[] parts = line.split("\\s+");

        for (int i = 0; i < parts.length; i++)
          ballot[i] = Integer.parseInt(parts[i]) - 1;

        results.add(ballot);

      }

      Boolean[] blacklist = new Boolean[n];
      for (int i = 0; i < n; i++) {
        blacklist[i] = false;
      }

      ArrayList<Integer> winners = new ArrayList<Integer>();

      while (true) {

        Integer[] sum = new Integer[n];
        for (int i = 0; i < n; i++)
          sum[i] = 0;

        int max = 0;
        int maxChoice = -1;

        for (int i = 0; i < results.size(); i++) {
          Integer[] r = results.get(i);
          int choice = -1;
          for (int j = 0; j < n; j++) {
            if (!blacklist[r[j]]) {
              choice = r[j];
              break;
            }
          }

          sum[choice]++;
          if (sum[choice] > max) {
            max = sum[choice];
            maxChoice = choice;
          }
        }

        if (max * 2 > results.size()) {
          winners.add(maxChoice);
          break;
        } else {

          int min = results.size();
          for (int i = 0; i < n; i++) {
            if (!blacklist[i] && (sum[i] < min)) min = sum[i];
          }

          for (int i = 0; i < n; i++) {
            if ((!blacklist[i]) && (sum[i] == min)) {
              if (min == max) {
                winners.add(i);
              } else {
                blacklist[i] = true;
              }
            }
          }

          if (min == max) break;

        }

      }

      for (int i = 0; i < winners.size(); i++) {
        System.out.println(names[winners.get(i)]);
      }

      if (testCases > 0) System.out.println();

    }

  }

}