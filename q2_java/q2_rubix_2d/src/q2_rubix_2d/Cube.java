package q2_rubix_2d;

public class Cube {
	private char[][]rbix = new char[3][3];
	
	public static void main(String[] args) {
		// for test
		Cube test = new Cube();
		test.cclear();
		test.cprint();
	}
	
	void cclear() {
		for(int i=0 ; i<3 ; i++) {
			for(int j=0 ; j<3 ; j++) {
				this.rbix[i][j] = '#';
			}
		}
		return;
	}
	
	void cprint() {
		for(int i=0 ; i<3 ; i++) {
			for(int j=0 ; j<3 ; j++) {
				System.out.print(this.rbix[i][j] + " ");
			}
			System.out.println("");
		}
		return;	
	}
	
	void setpoint(int yi, int xj, char ins) {
		this.rbix[yi][xj] = ins; 
	}
	
	void setrow(int yi, String s) {//ga ro <-->
		this.rbix[yi][0] = s.charAt(0);
		this.rbix[yi][1] = s.charAt(1);
		this.rbix[yi][2] = s.charAt(2);
	}
	
	void setcol_se(int xj, String s) {//sea ro ^V
		this.rbix[0][xj] = s.charAt(0);
		this.rbix[1][xj] = s.charAt(1);
		this.rbix[2][xj] = s.charAt(2);
	}
	
	
}
