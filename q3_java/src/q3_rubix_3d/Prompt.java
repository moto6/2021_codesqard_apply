package q3_rubix_3d;

import java.util.Scanner;

public class Prompt {
	static final String PROMPT = "CUBE> "; 
	static final String[] VALID_CMD = {"U'","U","R'","R","L'","L","B'","B"};
	public static void main(String[] args) {
		
		Cube c = new Cube();
		Scanner sc = new Scanner(System.in);
		String buf = "";
		cmd_initialize(c);

		
		while(true) {
			
			System.out.print(PROMPT);
			buf = sc.nextLine();
			
			if(buf.equals("Q") || buf.equals("q")) {
				cmd_finalize();
				break;
			}
			else if(buf.equals("H") || buf.equals("h") ) {
				cmd_help();
			}
			else if(buf.equals("@")) {
				buf = cmd_random_sfl();
				c.action(buf,c);
			}
			else {
				buf = cmd_senitizer(buf);
				c.action(buf,c);
			}
			
		}
	}
	
	//cmd_insert(buf,sc,c);
	static void cmd_insert(String buf,Scanner sc,Cube c) {
		for(int i=0 ; i<3 ; i++) {
			buf = sc.nextLine();
			
			for(int j=0 ; j<3 ; j++) {
				//c.setpoint(i, j, buf.charAt(j*2));
			}
		}
	}
	
	static String cmd_senitizer(String buf) {
		String ret = ""; //VALID_CMD = "URLB";
		int len = buf.length();
		for(int i=0 ; i<len ; i++) {
			for(int j=0 ; j<8 ; j++) {
				if (buf.startsWith(VALID_CMD[j])) {
					int length = VALID_CMD[j].length();
					ret += buf.substring(i, i+length);
					i++;
					break;
				}	
			}		 
		}
		return ret;
	}
	
	static void cmd_initialize(Cube c) {
		c.cinit();
		c.cprint();
	}
	
	static void cmd_finalize() {
		System.out.print("\n\n ====== Bye~ Bye~ =====\n");
		System.out.print("Elapsed time : "); /*@@@*/
		System.out.print("Additional implemented functions : \n");/*@@@*/
		System.out.print("\t- Random Shuffle \n\t- Time Display \n\t- Fit all sides\n");
		System.out.print("Number of operations : \n");/*@@@*/
		System.out.print("\n \t< END > \n\n");
	}
	
	
	static void cmd_help() {
		System.out.print("\n\n\n===== Help RubixCube Sim =====\n");
		System.out.print("1) Cube simulator\n");
		System.out.print("   - Press any key down blow\n");
		System.out.print("    : <F>   <R>   <U>   <B>   <L>  <D> \n");
		System.out.print("    : <F'>  <R'>  <U'>  <B'>  <L'>  <D'> \n");
		System.out.print("    ex) <FRR'U2R> : FRR'UUR  \n");
		System.out.print("\n");
		System.out.print("2) Terminate Program \n");
		System.out.print("   - Insert : <Q> \n");
		System.out.print("\n");
		System.out.print("3) Unit Test \n");
		System.out.print("   - <T1>, <T2>, <T3>, <T4>, <T5>\n");
		System.out.print("     - T1 : Cube Initialize and print test\n");
		System.out.print("     - T2 : insert commnad string, and convert to task \n");
		System.out.print("     - T3 : Random shuffle function \n");
		System.out.print("     - T4 : Validation check, inserted command from user \n");
		System.out.print("     - T5 : Cube activation only Single shot \n");
		System.out.print("\n");
		System.out.print("4) Additional functions");
		System.out.print("   - Random Shuffle : <@>");
		System.out.print("   - Fit all sides : <> ,no insert auto triggered");
		System.out.print(" \n===== Help End =====  ");
	}
	
	static String cmd_random_sfl() {
		String s = "";
		
		return s;
	}
	
}
