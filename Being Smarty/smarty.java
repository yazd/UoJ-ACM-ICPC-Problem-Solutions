import java.io.BufferedReader;
import java.io.FileReader;

public class smarty {
	public static void main(String[] args) throws Exception {		
		
		BufferedReader input = new BufferedReader(new FileReader("smarty.in"));

		String line;
		
		int cased = 0;
		
		while (!(line = input.readLine()).equals("0")) {
		
			cased++;
			
			line = fixInput(line);
			
			int end = line.indexOf(" ");
			
			int query = Integer.parseInt(line.substring(0,end)) - 1;
			
			int start = end+1;
			end = line.indexOf(" ", start);
			
			int n = Integer.parseInt(line.substring(start,end));
			
			line = line.substring(end+1);
			
			StringBuilder part = new StringBuilder();
			
			boolean opened = false;
			
			int index = 0;
			
			if (line.charAt(0) == '\"') {
				opened = true;
				index = 1;
			}
						
			for (; index < line.length(); index++) {
				if (opened)
					if (line.charAt(index) == '\"') {
						index++;
						break;
					} else
						part.append(line.charAt(index));
				else
					if (line.charAt(index) == ' ')
						break;
					else
						part.append(line.charAt(index));
			}
			
			String P1 = part.toString();
			
			part = new StringBuilder();
			
			index += 1;
			
			if ((line.length() > index) && (line.charAt(index) == '\"')) {
				opened = true;
				index ++;
			}
			
			for (; index < line.length(); index++) {
				if (opened)
					if (line.charAt(index) == '\"') {
						index++;
						break;
					} else
						part.append(line.charAt(index));
				else
					if (line.charAt(index) == ' ')
						break;
					else
						part.append(line.charAt(index));
			}
			
			String P2 = part.toString();
			
			if ( (query / n) % 2 == 0)
				System.out.println(cased + ". " + P1.toLowerCase());
			else
				System.out.println(cased + ". " + P2.toLowerCase());
			
		}
	}

	static String fixInput(String line) {
		
		StringBuilder output = new StringBuilder();
		
		int length = line.length();
		boolean previousSpace = false;
		boolean previousQuote = false;
		
		char c;
		
		for (int i = 0; i < length; i++) {
		
			c = line.charAt(i);
		
			if (c == '\"') {
				previousQuote = !previousQuote;
			}
			
			if (!previousQuote)
				if (c == ' ') {
					if (!previousSpace) {
						previousSpace = true;
						output.append(' ');
					} 
				} else {
					output.append(c);
					previousSpace = false;
				}
			else
				output.append(c);
			
		}
		
		return output.toString().trim();
		
	}
}
