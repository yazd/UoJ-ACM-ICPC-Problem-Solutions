import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class FizzBuzz {
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader in = new BufferedReader(new FileReader("FizzBuzz.in"));
		
		int count = Integer.parseInt(in.readLine());
		
		for (int i = 1; i <= count; i++) {
			
			if (i % 3 == 0)
				if (i % 5 == 0)
					System.out.println("FizzBuzz");
				else
					System.out.println("Fizz");
			else
				if (i % 5 == 0)
					System.out.println("Buzz");
				else
					System.out.println(i);
		
		}
		
	}
}

