package branks;

import java.util.Scanner;

public class Main {
	ArrModel stack;
	public Main() {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int inputcount=0,checkcount;
		
		while(inputcount<num) {
			String branks=sc.next();
			stack = new ArrModel(branks.length());
			checkcount=0;
			int k=0;
			while(k<branks.length()) {
				if(stack.ps==0) {
					push(branks.charAt(checkcount));
				}
				else if(stack.arr[stack.ps-1]==branks.charAt(checkcount)) {
					push(branks.charAt(checkcount));
				}else if(stack.arr[stack.ps-1]=='('){
					pop();
				}else {
					push(branks.charAt(checkcount));
				}
				checkcount++;
				k++;
			}
			if(stack.arr[0]!='x') {
				System.out.println("NO");
			}else if(stack.arr[0]=='x') {
				System.out.println("YES");
			}
			inputcount++;
		}
}
	public void push(char x) {stack.arr[stack.ps++]=x;}
	
	void pop() {
		stack.arr[--stack.ps]='x';
	}
	
	public static void main(String[] args) {
		Main a = new Main();
	}
}

class ArrModel{
	char[] arr;
	int ps=0;
	
	public ArrModel(int n) {
		arr = new char[n];
		for(int i=0; i<arr.length;i++) {
			arr[i]='x';
		}
	}
}
