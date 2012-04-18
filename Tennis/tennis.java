import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map.Entry;


public class tennis {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader("tennis.in"));
		
		String line = reader.readLine();
		
		int nChamps = Integer.parseInt(line);
		
		HashMap <String, Integer> champs = new HashMap<String, Integer>();
				
		while (true) {
			
			if (nChamps == 0) break;
			nChamps--;
			
			//read empty line
			
			reader.readLine();
			reader.readLine();
			reader.readLine();
			
			//
			
			line = reader.readLine();		
			String parts[] = line.split(": ");
	
			champs.put(parts[1], getPoints(champs,parts[1]) + 1000);
			
			line = reader.readLine();		
			parts = line.split(": ");
	
			champs.put(parts[1], getPoints(champs,parts[1]) + 600);
			
			for (int i = 0; i <= 1; i++) {
				line = reader.readLine();		
				parts = line.split(": ");
		
				champs.put(parts[1], getPoints(champs,parts[1]) + 360);
			}
			
			for (int i = 1; i <= 4; i++) {
				line = reader.readLine();		
				parts = line.split(": ");
		
				champs.put(parts[1], getPoints(champs,parts[1]) +180);
			}
			
		}
		
		System.out.println("Ranking:");
		System.out.println("");
			
		ArrayList <Player> players = new ArrayList<Player>();
		
		for (Entry<String, Integer> ch : champs.entrySet()) {
			
			Player p = new Player();
			
			p.name = ch.getKey();
			p.Points = ch.getValue();
			
			players.add(p);
			
		}
		
		Player p[] = new Player[players.size()];
		
		players.toArray(p);
		
		Arrays.sort(p);
		
		for (int i = 0; i < p.length; i++) {
			StringBuilder f = new StringBuilder();
			f.append(i + 1);
			f.append("- ");
			f.append(p[i].name);
			
			System.out.print(getProper(f));
			System.out.print(": ");
			System.out.println(p[i].Points);
		}
		
	}

	static int getPoints(HashMap <String, Integer> champs, String name) {
		if (champs.containsKey(name))
			return champs.get(name);
		return 0;
	}
	
	static String getProper(StringBuilder s) {
		
		for (int i = s.length(); i < 30; i++)
			s.append(" ");
		
		
		return s.toString();
	}
}

class Player implements Comparable<Player> {
	String name;
	int Points;
	public int compareTo(Player o) {
		if (this.Points > o.Points ) return -1;
		if (this.Points == o.Points) return 0;
		return 1;
	}
	
	
}