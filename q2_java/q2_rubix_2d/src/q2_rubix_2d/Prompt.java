package q2_rubix_2d;

import java.util.Scanner;

public class Prompt {
	static final String PROMPT = "CUBE> "; 
	static final char[] VALID_CMD = {'U','R','L','B'};
	public static void main(String[] args) {
		
		Cube c = new Cube();
		Scanner sc = new Scanner(System.in);
		String buf = "";
		
		cmd_insert(buf,sc,c);
		
		
		while(true) {
			
			System.out.print(PROMPT);
			buf = sc.nextLine();
			
			if(buf.equals("Q")) {
				break;
			}
			else {
				buf = cmd_senitizer(buf);
				System.out.println(buf);
				c.action(buf,c);
			}
			
		}	
	}
	
	static void cmd_insert(String buf,Scanner sc,Cube c) {
		for(int i=0 ; i<3 ; i++) {
			buf = sc.nextLine();
			
			for(int j=0 ; j<3 ; j++) {
				c.setpoint(i, j, buf.charAt(j*2));
			}
		}
	}
	
	static String cmd_senitizer(String buf) {
		//VALID_CMD = "URLB";
		String ret = "";
		int len = buf.length();
		
		for(int i=0 ; i<len ; i++) {
			
			for(int j=0 ; j<4 ; j++) {
				
				if( (len < i+1) && (buf.substring(i,i+1).equals("\'")) && VALID_CMD[j] == buf.charAt(i)) {
					ret += buf.substring(i, i+2);
					i++;
					break;
				}
				else if(VALID_CMD[j] == buf.charAt(i)) {
					ret += Character.toString(VALID_CMD[j]);
					break;
				}
				else {
					
				}
				
			}
				 
		}
		
		
		return ret;
	}
	
}
