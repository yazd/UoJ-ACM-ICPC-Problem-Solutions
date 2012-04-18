import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;


public class jungle {

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader reader = new BufferedReader(new FileReader("jungle.in"));
		
		while (true) {
			
			int nCities = Integer.parseInt(reader.readLine());
			if (nCities == 0) break;
			
			boolean bCities[] = new boolean[nCities];
			
			for (int i =0; i < nCities; i++)
				bCities[i] = false;
						
			City cities[] = new City[nCities];
			
			for (int i = 0; i < nCities; i++) {
				cities[i] = new City();
				//cities[i].edges = new Edge[0];
			}
			
			for (int i = 0; i < nCities - 1; i++ ) {
								
				String line = reader.readLine();
				
				String parts[] = line.split(" ");
								
				cities[i].index = i;
				
				//ArrayList<Edge> edges = new ArrayList<Edge>();
				
				for (int j = 2; j < parts.length; j+=2) {
					Edge e = new Edge();
					e.city1 = i ;
					e.city2 = parts[j].charAt(0) - 'A';
					e.cost = Integer.parseInt(parts[j+1]);
					
					cities[e.city1].aE.add(e);
					cities[e.city2].aE.add(e);
					
				}
				
				

				
			}
			
			for (int i = 0; i < nCities; i++) {
				cities[i].edges = new Edge[cities[i].aE.size()];
				cities[i].aE.toArray(cities[i].edges);
				Arrays.sort(cities[i].edges);
			}
			
			int cost = 0;
			
			PriorityQueue<Edge> edges = new PriorityQueue<Edge> ();
			
			int nCheckedCities = 0;
			
			for (int ed = 0; ed < cities[0].edges.length; ed++) {
				edges.offer(cities[0].edges[ed]);
			}
			
			while (nCheckedCities < nCities) {
				
				Edge e = edges.poll();
					
				if (bCities[e.city1] && bCities[e.city2]) continue;
				
				cost += e.cost;
				if (!bCities[e.city1]) { 
					bCities[e.city1] = true;
					nCheckedCities ++;
					
					for (int ed = 0; ed < cities[e.city1].edges.length; ed++) {
						edges.offer(cities[e.city1].edges[ed]);
					}
					
				}
				
				if (!bCities[e.city2]) {
					bCities[e.city2] = true;
					nCheckedCities ++;
					
					for (int ed = 0; ed < cities[e.city2].edges.length; ed++) {
						edges.offer(cities[e.city2].edges[ed]);
					}
				}
				
			
			}
		
			System.out.println(cost);
			
		}

	}

}

class City {

	int index;
	Edge edges[];
	
	ArrayList<Edge> aE = new ArrayList<Edge>();
}

class Edge implements Comparable<Edge> {
	
	int city1;
	int city2;
	
	int cost;

	public int compareTo(Edge o) {
		if (this.cost > o.cost) return 1;
		if (this.cost < o.cost) return -1;
		return 0;
	}

	@Override
	public String toString() {
		return "Edge [city1=" + city1 + ", city2=" + city2 + ", cost=" + cost
				+ "]";
	}
	
}