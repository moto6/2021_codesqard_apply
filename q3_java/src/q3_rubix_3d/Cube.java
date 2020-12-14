package q3_rubix_3d;

class Qstring{
	public String CMD;
	Qstring(String ins) {
		this.CMD = ins;
	}
}


public class Cube {
	
	static final char[] INITCUBE = {'B','W','O','G','Y','R'}; 
	static final String[] VALID_CMD = {"U'","U","R'","R","L'","L","B'","B"};
	private char[][][]rbix = new char[6][3][3];
	
	public static void main(String[] args) {
		System.out.println("Prompt파일을 실행해주세요!");
		
		//for test
		Cube test = new Cube();
		//test.cinit();
		//test.cprint();
	}
	
	void cinit() {
		for(int k=0 ; k<6 ; k++) {
			for(int i=0 ; i<3 ; i++) {
				for(int j=0 ; j<3 ; j++) {
					this.rbix[k][i][j] = INITCUBE[k];
				}
			}
		}
		return;
	}
	
	void cprint() {
		String ADJUSTER = "                ";
		
		//up side print
		for (int i = 0; i < 3; i++) {
			System.out.print(ADJUSTER);
			for (int j = 0; j < 3; j++) {
				System.out.print(this.rbix[0][i][j] + " ");
			}
			System.out.println("");
		}
		System.out.print("\n");
		
		//side faces print
		for(int i=0 ; i<3 ; i++) {
			for(int j=1 ; j<=4 ; j++) {
				for(int k=0 ; k<3 ; k++) {
					System.out.print(this.rbix[j][i][k] + " ");
				}
				System.out.print("     ");
			}
			System.out.print("\n");
		}
		System.out.print("\n");
		
		//down side print
		for (int i = 0; i < 3; i++) {
			System.out.print(ADJUSTER);
			for (int j = 0; j < 3; j++) {
				System.out.print(this.rbix[5][i][j] + " ");
			}
			System.out.println("");
		}
		return;	
	}
	
	
	void setpoint(int side,int yi, int xj, char ins) {
		this.rbix[side][yi][xj] = ins; 
	}
	/*
	String set_row(int side, int yi, String s) {
		
	}
	String set_col(int side, int xj, String s) {
		
	}
	*/
	String get_2d_row(int side,int yi) {
		String tmp = "";
		//char[] tmp = new char[3];
		tmp += this.rbix[side][yi][0];
		tmp += this.rbix[side][yi][1];
		tmp += this.rbix[side][yi][2];
		return tmp;
	}
	String set_2d_row(int side,int yi, String s) {
		//ga ro <-->
		//char[] tmp = new char[3];
		String tmp = "";
		tmp += this.rbix[side][yi][0];
		//System.out.println(tmp);
		tmp += this.rbix[side][yi][1];
		//System.out.println(tmp);
		tmp += this.rbix[side][yi][2];
		this.rbix[side][yi][0] = s.charAt(0);
		this.rbix[side][yi][1] = s.charAt(1);
		this.rbix[side][yi][2] = s.charAt(2);
		//String st = tmp.toString();
		//System.out.println(tmp);
		return tmp;
	}
	
	String set_2d_col(int side,int xj, String s) {
		//sea ro ^V
		char[] tmp = new char[3];
		tmp[0] = this.rbix[side][0][xj];
		tmp[1] = this.rbix[side][1][xj];
		tmp[2] = this.rbix[side][2][xj];
		this.rbix[side][0][xj] = s.charAt(0);
		this.rbix[side][1][xj] = s.charAt(1);
		this.rbix[side][2][xj] = s.charAt(2);
		return tmp.toString();
	}
	
	public void action(String buf, Cube c) {

		while (true) {// System.out.print(buf); :명령어 확인용
			Qstring sptr = new Qstring(buf);
			// 삭제예정// String spointer = buf; //System.out.print("\nBeFORe CMD : "+sptr+"\n");
			int cmdnum = cmd_strQ_pop(sptr);

			if (cmdnum == 0) {
				c.U_prime();
				System.out.print("uprime\n");
			} else if (cmdnum == 1) {
				c.U_nomal();
			} else if (cmdnum == 2) {
				c.R_prime();
			} else if (cmdnum == 3) {
				c.R_nomal();
			} else if (cmdnum == 4) {
				//c.L_prime();
			} else if (cmdnum == 5) {
				//c.L_nomal();
			} else if (cmdnum == 6) {
				//c.B_prime();
			} else if (cmdnum == 7) {
				//c.B_nomal();
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
		//0:up
		//1,2,3,4 : m1m2m3m4
		String temp = get_2d_row(1,0);
		set_2d_row(1, 0, get_2d_row(2,0));
		set_2d_row(2, 0, get_2d_row(3,0));
		set_2d_row(3, 0, get_2d_row(4,0));
		set_2d_row(4, 0, temp);
		/*
		String temp = get_2d_row(1,0);
		for(int i=1 ; i<=4 ; i++) {
			temp = set_2d_row(i,0,temp);
		}*/
	}
	
	void U_nomal() {//
		String temp = get_2d_row(4,0);
		set_2d_row(4, 0, get_2d_row(3,0));
		set_2d_row(3, 0, get_2d_row(2,0));
		set_2d_row(2, 0, get_2d_row(1,0));
		set_2d_row(1, 0, temp);
	}
	
	void R_prime() {
		String temp = get_2d_row(0, 2);
		set_2d_col(0, 2, get_2d_row(3, 2));
		set_2d_col(3, 2, get_2d_row(5, 2));
		set_2d_col(5, 2, get_2d_row(1, 2));
		set_2d_col(1, 2, temp);
	}
	
	void R_nomal() {
		String temp = get_2d_row(1, 2);
		set_2d_col(1, 2, get_2d_row(5, 2));
		set_2d_col(5, 2, get_2d_row(3, 2));
		set_2d_col(3, 2, get_2d_row(0, 2));
		set_2d_col(0, 2, temp);
	}
	
	void L_prime() {
		String temp = get_2d_row(0,0);
		set_2d_col(0, 0, get_2d_row(3,0));
		set_2d_col(3, 0, get_2d_row(5,0));
		set_2d_col(5, 0, get_2d_row(1,0));
		set_2d_col(1, 0, temp);
	}
	
	void L_nomal() {
		String temp = get_2d_row(1,0);
		set_2d_col(1, 0, get_2d_row(5,0));
		set_2d_col(5, 0, get_2d_row(3,0));
		set_2d_col(3, 0, get_2d_row(0,0));
		set_2d_col(0, 0, temp);
	}
	
	void B_prime() {
		String temp = get_2d_row(1,2);
		set_2d_row(1, 2, get_2d_row(2,2));
		set_2d_row(2, 2, get_2d_row(3,2));
		set_2d_row(3, 2, get_2d_row(4,2));
		set_2d_row(4, 2, temp);
	}
	void B_nomal() {
		String temp = get_2d_row(4,2);
		set_2d_row(4, 2, get_2d_row(3,2));
		set_2d_row(3, 2, get_2d_row(2,2));
		set_2d_row(2, 2, get_2d_row(1,2));
		set_2d_row(1, 2, temp);
	}
	
}
