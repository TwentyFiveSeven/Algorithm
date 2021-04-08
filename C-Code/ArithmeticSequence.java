package ArithmeticSequence;

import java.util.Scanner;

public class Main {
	ArrModel fiarr;
	ArrModel scarr;
	public Main() {
		Scanner sc = new Scanner(System.in);
		int count = sc.nextInt();
		int Scount =0;
		char[] print = new char[count*2];
		int k=0;
		fiarr = new ArrModel(count);
		scarr = new ArrModel(count);
		int[] Sequence = new int[count];
		makeArr(fiarr.arr);	
		
		for(int i=0;i<count;i++) {
			Sequence[i]=sc.nextInt();
		}
	F1:	while(true) {
			if(scarr.ps==0&&fiarr.ps>count-1) {
				for(int i=0;i<print.length;i++) {
					System.out.println(print[i]);
				}
				break;
			}
			else if(scarr.ps==0) {
				print[k++]=push(fiarr.arr[fiarr.ps]);
			}
			else if(scarr.ps!=00&&Sequence[Scount]==scarr.arr[scarr.ps-1]) {
				print[k++]=pop(scarr);
				Scount++;
			}else {
				if(Sequence[Scount]!=scarr.arr[scarr.ps-1]&&fiarr.ps>=count) {
					System.out.println("NO");
					break F1;
				}
				else {
					print[k++]= push(fiarr.arr[fiarr.ps]);
				}
			}
		}
	}
	
	void makeArr(int[] arr) {
		for(int i=1; i<=arr.length;i++) {
			arr[i-1]=i;
		}
	}
	
	char push(int n) {
		scarr.arr[scarr.ps]=n;
		scarr.ps++;
		fiarr.ps++;
		return '+';
	}
	
	char pop(ArrModel model) {
		if(model.ps==0) {
			return 'x';
		}else {
			model.arr[--model.ps]=0;
		}
		return '-';
	}
	
	public static void main(String args[]) {
		Main a =new Main();
	}
}

class ArrModel {
	int ps;
	int[] arr;
	
	public ArrModel(int n) {
		arr = new int[n];
	}
}
