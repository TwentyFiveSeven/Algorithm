package BranksValue;

import java.util.Scanner;

public class Main {
	BranksModel[] arr;
	int ps;
	public Main() {
		Scanner sc = new Scanner(System.in);
		int i =0;
		int sum=0;
		int save=0;
		String input = sc.next();
		arr = new BranksModel[input.length()];
		int[] caluator = new int[input.length()];
		
	F1:	while(i<input.length()) {
			if(ps==0) {
				push(arr,input.charAt(0));
			}else {
				switch(arr[ps-1].direction) {
				case '(' :
					if(input.charAt(i)=='('||input.charAt(i)=='[') {
						arr[ps-1].multi=1;
						push(arr,input.charAt(i));
					}else if(input.charAt(i)==')') {
						if(ps-2>=0) {
							if(arr[ps-2].save!=1)
								arr[ps-2].save = arr[ps-2].save+arr[ps-1].value*arr[ps-1].save;
							else {
								arr[ps-2].save = arr[ps-1].value*arr[ps-1].save;
							}
							pop(arr[ps-1]);
						}else {
							sum =sum+arr[ps-1].save*arr[ps-1].value;
							pop(arr[ps-1]);
						}
					}else {
						System.out.println(0);
						break F1;
					}
					break;
				case '[' :
					if(input.charAt(i)=='('||input.charAt(i)=='[') {
						arr[ps-1].multi=1;
						push(arr,input.charAt(i));
					}else if(input.charAt(i)==']') {
						if(ps-2>=0) {
							if(arr[ps-2].save!=1)
								arr[ps-2].save = arr[ps-2].save+arr[ps-1].value*arr[ps-1].save;
							else {
								arr[ps-2].save = arr[ps-1].value*arr[ps-1].save;
							}
							pop(arr[ps-1]);
						}else {
							sum =sum+arr[ps-1].save*arr[ps-1].value;
							pop(arr[ps-1]);
						}
					}else {
						System.out.println(0);
						break F1;
					}
					break;
				}
			}
			i++;
			if(i==input.length()) {
			System.out.println(sum);
			}
		}
	}
	
	void push(BranksModel[] bm, char c) {
		bm[ps++] = new BranksModel(c);
		
	}
	
	void pop(BranksModel bm) {
		bm.direction=0;
		bm.multi=0;
		bm.save=0;
		bm.value=0;
		ps--;
	}
	public static void main(String[] args) {
		Main a = new Main();
	}
}

class BranksModel{
	char direction;
	int value;
	int multi=0;
	int save=1;
	
	public BranksModel(char val) {
		if(val=='(') {
			this.direction=val;
			this.value = 2;
		}else if(val==')') {
			this.direction=val;
			this.value = 2;
		}else if(val=='[') {
			this.direction=val;
			this.value = 3;
		}else if(val==']'){
			this.direction=val;
			this.value = 3;
		}
	}
}
