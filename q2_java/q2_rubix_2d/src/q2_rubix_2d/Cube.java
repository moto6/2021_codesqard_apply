package q2_rubix_2d;

class Qstring{
	public String CMD;
	Qstring(String ins) {
		this.CMD = ins;
	}
}


public class Cube {
	static final String[] VALID_CMD = {"U'","U","R'","R","L'","L","B'","B"};
	private char[][]rbix = new char[3][3];
	
	public static void main(String[] args) {
		System.out.println("Prompt파일을 실행해주세요!");
		
		// for test
		//Cube test = new Cube();
		//test.cclear();
		//test.cprint();
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
	
	public void action(String buf, Cube c) {

		while (true) {// System.out.print(buf); :명령어 확인용
			Qstring sptr = new Qstring(buf);
			// 삭제예정// String spointer = buf; //System.out.print("\nBeFORe CMD : "+sptr+"\n");
			int cmdnum = cmd_strQ_pop(sptr);

			if (cmdnum == 0) {
				c.U_prime();
			} else if (cmdnum == 1) {
				c.U_nomal();
			} else if (cmdnum == 2) {
				c.R_prime();
			} else if (cmdnum == 3) {
				c.R_nomal();
			} else if (cmdnum == 4) {
				c.L_prime();
			} else if (cmdnum == 5) {
				c.L_nomal();
			} else if (cmdnum == 6) {
				c.B_prime();
			} else if (cmdnum == 7) {
				c.B_nomal();
			} else {
				System.out.println("cmd_strQ_pop ERROR : "+cmdnum);
			}
			buf = sptr.CMD;
			if (buf.length() == 0) {
				break;
			}
		}

		c.cprint();

		buf = "";
		return;
	}

	int cmd_strQ_pop(Qstring ins) {
		//VALID_CMD = {"U'","U","R'","R","L'","L","B'","B"};
		int ret = -1;
		
		String tmp = ins.CMD;
		
		for(int i=0 ; i<8 ; i++) {
			if(tmp.startsWith(VALID_CMD[i])) {
				//ins = ins.substring(VALID_CMD[i].length());
				ins.CMD = tmp.substring(VALID_CMD[i].length());
				//System.out.print("num : ");
				//System.out.print(i);
				return i;
			}
		}
		return ret;
	}
	
	void U_prime() {
		char temp = this.rbix[0][2];
		this.rbix[0][2] = this.rbix[0][1]; 
		this.rbix[0][1] = this.rbix[0][0];
		this.rbix[0][0] = temp;
	}
	
	void U_nomal() {
		char temp = this.rbix[0][0];
		this.rbix[0][0] = this.rbix[0][1]; 
		this.rbix[0][1] = this.rbix[0][2];
		this.rbix[0][2] = temp;
	}
	
	
	void R_prime() {
		char temp = this.rbix[2][2];
		this.rbix[2][2] = this.rbix[1][2];
		this.rbix[1][2] = this.rbix[0][2];
		this.rbix[0][2] = temp;
	}
	
	void R_nomal() {
		char temp = this.rbix[0][2];
		this.rbix[0][2] = this.rbix[1][2];
		this.rbix[1][2] = this.rbix[2][2];
		this.rbix[2][2] = temp;
	}
	
	void L_prime() {
		char temp = this.rbix[2][0];
		this.rbix[2][0] = this.rbix[1][0];
		this.rbix[1][0] = this.rbix[0][0];
		this.rbix[0][0] = temp;
	}
	
	void L_nomal() {
		char temp = this.rbix[0][0];
		this.rbix[0][0] = this.rbix[1][0];
		this.rbix[1][0] = this.rbix[2][0];
		this.rbix[2][0] = temp;
	}
	
	void B_prime() {
		char temp = this.rbix[2][2];
		this.rbix[2][2] = this.rbix[2][1]; 
		this.rbix[2][1] = this.rbix[2][0];
		this.rbix[2][0] = temp;
	}
	void B_nomal() {
		char temp = this.rbix[2][0];
		this.rbix[2][0] = this.rbix[2][1]; 
		this.rbix[2][1] = this.rbix[2][2];
		this.rbix[2][2] = temp;
	}
	
}
