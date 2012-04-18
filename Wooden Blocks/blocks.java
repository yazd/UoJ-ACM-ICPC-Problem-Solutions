import java.io.BufferedReader;
import java.io.InputStreamReader;


public class blocks {
	
	public static void main(String[] args) throws Exception {

		BufferedReader input = new BufferedReader(new FileReader("blocks.in"));
		
		boolean[][] fits = {
				{false, false, false, true, true, false, false, false}, 
				{false, false, false, false, false, false, false, false}, 
				{false, false, false, true, true, false, false, false},
				{false, true, true, false, false, false, false, false},
				{false, false, false, false, false, false, false, true},
				{false, true, true, false , false, false, false, false},
				{false, false, false, false, false, false, false, true},
				{false, false, false, false, false, true, true, false}
		};
		
		int c = 0;
		
		String line;
		
		while (!(line = input.readLine()).equals("0")) {
			
			if (line.equals("")) continue;
			
			c++;
			
			boolean valid = true;
			
			if ((line.charAt(0) != '1') || (!line.endsWith("2"))) 
				valid = false;
			else {
				
				int left;
				int right;
				
				for (int i = 0; i < line.length() - 1; i++) {
				
					left = line.charAt(i) - '1';
					right = line.charAt(i+1) - '1';

					if ((left < 0) || (right < 0)) {
						valid = false;
						break;
					}
					
					if ((left > 7) || (right > 7)) {
						valid = false;
						break;
					}
					
					if (!fits[left][right]) {
						valid = false;
						break;
					}
					
				}
			
			}
			
			if (valid)
				System.out.println(c + ". VALID");
			else
				System.out.println(c + ". NOT");
		}

	}

}
