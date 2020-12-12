package q2_rubix_2d;

import java.util.Scanner;

public class Prompt {
	static final String PROMPT = "CUBE> "; 
	
	public static void main(String[] args) {
		
		Cube c = new Cube();
		Scanner sc = new Scanner(System.in);
		String buf;
		for(int i=0 ; i<3 ; i++) {
			buf = sc.nextLine();
			
			for(int j=0 ; j<3 ; j++) {
				c.setpoint(i, j, buf.charAt(j*2));
			}
		}
		
		
		while(true) {
			System.out.println(PROMPT);
			buf = sc.nextLine();
			if(buf.equals("Q")) {
				break;
			}
			else {
				
				c.cprint();
			}
			
			
			
			
			
		}
		
	}
}
