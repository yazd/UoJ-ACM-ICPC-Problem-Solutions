import java.util.*;
import java.io.*;
import java.util.regex.*;

class erdos {
  public static void main(String args[]) throws Exception {

    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    int test_cases = Integer.parseInt(reader.readLine().trim());
    int current_case = 0;

    Pattern space = Pattern.compile("\\s+");
    Pattern name_pattern = Pattern.compile("\\.\\s*,");

    while (current_case++ < test_cases) {

      int lines_count, query_count;

      String parts[] = space.split(reader.readLine().trim()); //.split("\\s+");
      lines_count = Integer.parseInt(parts[0].trim());
      query_count = Integer.parseInt(parts[1].trim());

      HashMap<Integer, HashSet<Integer>> connections = new HashMap<Integer, HashSet<Integer>>();
      HashMap<String, Integer> names = new HashMap<String, Integer>();
      int id = 0;

      for (int i = 0; i < lines_count; i++) {
        
        String line = reader.readLine();

        parts = line.split(":");
        if (!parts[0].endsWith(".")) parts[0] += ".";
        parts[0] += ",";

        parts = name_pattern.split(parts[0]);

        HashSet<Integer> n = new HashSet<Integer>();

        for (int j = 0; j < parts.length; j++) {
          
          String name = parts[j].trim().toLowerCase() + ".";
          name = name.replaceAll("\\s+", " ");

          int index;

          if (!names.containsKey(name)) {
            index = id++;
            names.put(name, index);
          } else {
            index = names.get(name);
          }

          n.add(index);

        }

        for (int in : n) {
          
          if (!connections.containsKey(in)) {
            connections.put(in, new HashSet<Integer>());
          }

          connections.get(in).addAll(n);

        }

      }

      int size = id;

      int erdos_index = names.get("erdos, p.");
      Integer[] result = new Integer[size];

      for (int i = 0; i < size; i++) {
        result[i] = Integer.MAX_VALUE;
      }

      HashSet<Integer> query = new HashSet<Integer>();
      ArrayList<String> query_names = new ArrayList<String>();

      for (int i = 0; i < query_count; i++) {
        String name = reader.readLine().trim();
        name = name.replaceAll("\\s+", " ");
        query_names.add(name);

        String searched_name = name.toLowerCase();
        if (!searched_name.endsWith(".")) searched_name += ".";

        if (names.containsKey(searched_name)) {
          int opp_index = names.get(searched_name);
          query.add(opp_index);
        }
      }

      PriorityQueue<Edge> edges = new PriorityQueue<Edge>();

      Edge e = new Edge();
      e.origin = erdos_index;
      e.dst = erdos_index;
      e.cost = 0;
      result[erdos_index] = 0;
      edges.add(e);

      while (!edges.isEmpty()) {
        Edge top = edges.poll();

        if (top.cost == Integer.MAX_VALUE) break;

        query.remove(top.dst);
        if (query.isEmpty()) break;

        for (int dst : connections.get(top.dst)) {

          if (dst == top.dst) continue;

          Edge edge = new Edge();

          edge.origin = top.dst;
          edge.dst = dst;

          if (result[top.dst] == Integer.MAX_VALUE) {
            edge.cost = result[dst];
          } else {
            edge.cost = Math.min(result[top.dst] + 1, result[dst]);
          }

          edges.add(edge);
            
          result[dst] = edge.cost;

        }

        connections.get(top.dst).clear();
      }

      System.out.println("Scenario " + current_case);

      for (String name : query_names) {
        
        String searched_name = name.toLowerCase();
        if (!searched_name.endsWith(".")) searched_name += ".";
        int cost;

        if (names.containsKey(searched_name)) {
          int opp_index = names.get(searched_name);
          cost = result[opp_index];
        } else {
          cost = Integer.MAX_VALUE;
        }
        
        System.out.print(name + " ");

        if (cost == Integer.MAX_VALUE) {
          System.out.println("infinity");
        } else {
          System.out.println(cost);
        }
      }

    }

  }

  static class Edge implements Comparable {
    int origin;
    int dst;
    int cost;

    public int compareTo(Object obj) {
      Edge that = (Edge) obj;

      if (this.cost > that.cost) return 1;
      if (this.cost < that.cost) return -1;
      
      return 0;
    }

  }

}