#include "pch.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<cmath>
#include<string>
#include<queue>
#include<map>
using namespace std;

typedef struct {
	string func= "";
	vector<string> V;
}FUNC;
string printS = "";
vector<string> Tree;
stack<int> Stack;
map<string, FUNC> M;
map<string, string> VM;

int selectMenu();
int defineDEFUN();
int Interpreter();
string Result(string &s,int check);
int checkBlank(string s);
string Exception(int N);
int makeTree(int i, int index, string s);
void postorder(int index);
int MINUS();
int IF();
int makeString(string &s);
void retVar(string s, string defun, int j, int &i);
void CheckTimes(string &s);
void CheckString(string &s);
void loadDEFUN();
void readwriteFile(string filePath, string S);

int main() {
	M["MINUS"].V.push_back("abc1");
	M["MINUS"].V.push_back("abc2");
	M["IF"].V.push_back("abc3");
	M["IF"].V.push_back("abc4");
	int select = 0;	// 메뉴선택 변수
	while (1) {
		select = selectMenu(); //메뉴 선택하는 함수 호출
		switch (select) { // 선택 값에 따른 함수 호출
		case 1:	//1번 File load 선택
			defineDEFUN();
			//Fileload();
			break;
		case 2:	//2번 Interactive Mode 선택
			loadDEFUN();
			//interactiveMode();
			break;
		case 3:
			Interpreter();
			break;
		case 4: //3번 Exit 선택
			cout << "프로그램을 종료합니다.";
			return 0;
			break;
		}
	}
}

int selectMenu() {	//메뉴를 선택하는 함수
	int ret = 0;
	cout << "===================================" << '\n';
	cout << "1. Define DEFUN" << '\n';
	cout << "2. Print DEFUN" << '\n';
	cout << "3. Interpreter" << '\n';
	cout << "4. Exit" << '\n';
	cout << "===================================" << '\n';
	cout << "메뉴를 선택하세요 >> ";
	cin >> ret;	//메뉴 입력
	return ret;	//선택 번호 return
}

int defineDEFUN() {	//DEFUN 작성 모드
	string S = "", C = "";	//바로 getline을 받을시에 전에 누적된 엔터 스트림에 의해 입력이 무시되므로
	char temp;			// char변수 temp 를 입력받을 때 첫글자가 temp에 입력되어 사라지는것을 방지
	string filePath = "defun.txt";
	cin >> temp;//바로 getline을 받을시에 전에 누적된 엔터 스트림에의해 입력이 무시되는것을 막는다.
	S += temp;	//temp로 입력되는 값을 저장한다.
	getline(cin, C);//문자열을 입력받는다.
	S += C;		//temp로 입력된 char값과 C의 String값을 더한다.
	int Findex = S.find('(', 0); // 변수 선언 시작부분을 찾는다.
	int Vindex = S.find(')', Findex); // 변수 선언 끝 부분을 찾는다.
	string tag = S.substr(0, Findex); // DEFUN Name을 찾는다.
	string vari = S.substr(Findex, Vindex - Findex + 1); // 변수 선언부분을 저장한다.
	string s = "";
	for (int i = 0; i < (int)(tag.size()); i++) { // DEFUN Name부분을 찾습니다.
		if (tag[i] >= 'A' && tag[i] <= 'Z')
			s += tag[i];
	}
	if (M.count(s) > 0) { //만약 이미 존재한다면 에러출력
		cout << "이미 정의된 함수입니다." << '\n';
		return 0;
	}
	int count = 0;
	for (int i = 0; i < (int)(vari.size()); i++) { //변수를 찾는다.
		if (vari[i] == ' ' || vari[i] == ')' || vari[i] == '(')continue;
		string Var = "";
		while (vari[i] != ' ' && vari[i] != ')') {
			Var += vari[i];
			i++;
		}
		count++;
	}
	if (count == 0) { //만약 매개변수가 하나도 없다면 에러 출력.
		cout << "매개변수가 하나도 존재하지 않습니다." << '\n';
		return 0;
	}
	readwriteFile(filePath, S); // 작성한 DEFUN을  defun.txt에 추가.
	return 0;
}

void loadDEFUN() { // DEFUN을 불러오는 함수이다.
	string fp = "defun.txt";
	ifstream openFile(fp.data());	//파일을 열어 데이터를 읽는다.
	if (openFile.is_open()) {	//만약 파일 이름이 존재하다면 True
		string line;
		while (getline(openFile, line)) {	// getline함수를 사용하여 한줄씩 String으로 읽는다.
			int size = line.size();
			cout << line<<'\n'; //읽어온 line을 출력한다.
			int Findex = line.find('(', 0); // 변수선언의 시작지점을 찾는다.
			int Vindex = line.find(')', Findex); // 변수선언의 끝지점을 찾는다.
			string tag = line.substr(0, Findex-1); // DEFUN의 NAME값을 찾는다.
			if (M.count(tag) > 0) continue; //만약에 이미 존재하는 DEFUN이라면 다음 줄을 읽는다.
			string vari = line.substr(Findex, Vindex - Findex + 1);	// 변수선언부를 저장.
			string Fun = line.substr(Vindex + 2, size - (Vindex+1)); // DEFUN의 내용을 저장해놓는다.
			string s=tag;
			for (int i = 0; i < (int)(vari.size()); i++) {	//변수선언부를 돌면서 변수를 저장한다.
				if (vari[i] == ' ' || vari[i] == ')' || vari[i] =='(' )continue;
				string Var = "";
				while (vari[i] != ' ' && vari[i] != ')') { //변수의 이름을 가져온다.
					Var += vari[i];
					i++;
				}
				M[s].V.push_back(Var);	//완성된 변수를 DEFUN Key를 가진 Map의 vector안에 저장한다.
			}
			if (Fun[0] == ' ') Fun = Fun.substr(1, size - 1);
			M[s].func = Fun; // 함수를 DEFUN Key를 가진 Map의 vector안에 저장한다.
		}
		openFile.close();
	}
	return;
}

int Interpreter() {	//File Load하는 함수
	int size = 0, flag = 1;	// flag는 파일 이름이 존재하는지 확인하는 변수
	vector<string> S;		// File에서 String 한줄씩 읽어서 S 벡터에 저장한다.
	string fp = ""; // 파일 이름저장
	while (flag) {
		cout << "실행 파일명을 입력하세요 >> ";
		cin >> fp;
		ifstream openFile(fp.data());	//파일을 열어 데이터를 읽는다.
		if (openFile.is_open()) {	//만약 파일 이름이 존재하다면 True
			string line;
			while (getline(openFile, line)) {	// getline함수를 사용하여 한줄씩 String으로 읽는다.
				cout << "***********************************" << '\n';
				cout << line << " -> ";	//읽은 줄 출력
				string ans = Result(line, 0); //읽은 줄에 대한 결과값을 구한다.
				cout << "Result : " << ans << '\n' << '\n'; //결과값 출력
			}
			openFile.close();
			flag = 0;	//파일 이름이 존재한다는 뜻으로 flag =0으로 바꿔주고 while문을 종료한다.
		}
		else { //만약 파일 이름이 존재하지 않다면 에러 출력후 다시 while문의 처음으로 돌아간다.
			cout << "\n파일 이름이 존재하지 않습니다." << '\n';
			cout << "***********************************" << '\n';
		}
	}
	return 0;
}

void readwriteFile(string filePath,string S) { //새로 정의한 DEFUN을 defun.txt 파일 가장 아래줄에 저장한다.
	string text = "";
	ofstream writeFile(filePath, ios::app);
	if (writeFile.is_open()) {
		writeFile << '\n' << S;
	}
	writeFile.close();
}

string Result(string &s,int check) { //연산식인 s에 대한 결과를 출력한다.
	int size = checkBlank(s);	//에러를 체크한다. 만일 에러가 있을시 0보다 작거나 같은 값으로 return
	if (size <= 0) {  //예외처리
		return Exception(size);	//예외번호를 결과로 출력한다.
	}
	if (check == 0) { //check 파라미터가 0이라면 String을 check하여 모두 MINUS와 IF로 만들어준다.
		CheckString(s);
		cout << s << '\n';
	}
	size = checkBlank(s); //새로 만들어진 함수 사이즈를 정의하고 다시한번더 문자열을 체크한다.
	int Vsize = 1 << (size + 2);// size값은 괄호 쌍의 수를 의미하므로 +2한만큼 2의 제곱을해준다.
	Tree.clear();
	Tree.resize(Vsize);//Tree의 size를 재정의해준다.
	makeTree(0, 0, s);	//문자열을 파싱하여 트리를 만들어준다.
	while (!Stack.empty()) Stack.pop();
	postorder(0);//Tree를 Postorder로 순회하여 결과값을 구한다.
	if(check == 0)
		cout << "Prefix To Postfix : " << printS << '\n'; //check ==0일 때 Prefix to postfix값을 출력한다.
	printS = "";
	return to_string(Stack.top());//마지막남은 하나의 값을 string으로 변환하여 return 한다.
}

int checkBlank(string s) {	//문자열의 에러를 찾는 함수이다
	vector<char> V;
	int ret = 0;
	int size = s.size();
	for (int i = 0; i < size; i++) {
		if (s[i] == ' ') continue;// s[i]값이 공백이면 넘긴다.
		if (s[i] != '('&&s[i] != ')' && s[i] != '-')// 입력값이 '(', ')', '-', 숫자, 알파벳이 아니면 에러표시
			if (s[i]<'0' || s[i]>'9')				// 입력값이 '(', ')', '-', 숫자, 알파벳이 아니면 에러표시
				if (s[i]<'A' || s[i] > 'Z')			// 입력값이 '(', ')', '-', 숫자, 알파벳이 아니면 에러표시
					if (s[i]<'a' || s[i]> 'z')		// 입력값이 '(', ')', '-', 숫자, 알파벳이 아니면 에러표시
						return -1; //알파벳과 '-'를 제외한 기호입력시 에러
		if (s[i] == ')') {
			if (V.size() > 0) {	//'('괄호가 있다면 pop해주고 괄호쌍수를 뜻하는 ret변수에 1을 더해준다.
				V.pop_back();
				ret++;
			}
			else if (V.size() == 0)	//벡터안에 '('문자가 없다면 ')'문자를 push해주고 반복문을 멈춘다.
			{
				V.push_back(')');
				break;
			}
		}
		else if (s[i] == '(')	// '('문자라면 벡터에 push해준다.
			V.push_back('(');
		else if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) { //입력값이 알파벳이라면 명령어를 찾는다.
			int index = s.find(' ', i);//현재 위치 i에서 다음 공백문자가 나오는 위치를 찾는다.
			string temp = s.substr(i, index - i);//temp변수에 명령어 문자열을 저장한다.
				if (M.count(temp) == 0) //undefined 오류를 뜻하는 -2를 return 한다, 카운트값이 0이라면 정의되지 않은 함수이다.
					return -2;
				else { //만약 정의 되었다면 .
					vector<char> C;
					int limit = M[temp].V.size(), Vcount = 0; //DEFUN이 가지고 있는 매개변수 수를 가져온다.
					i = index;//MINUS나 IF였을 때는 문자열의 길이만큼 i를 증가시킨다.
					for (int j = i; j < (int)(s.size());j++) { //DEFUN이 가지고 있는 매개변수 만큼을 작성하였는지 확인한다.
						while (s[j] == ' ')j++;
						if ((s[j] >= '0' && s[j] <= '9') || s[j] == '-') { //매개변수가 숫자값이면
							while (s[j] != ' ' && s[j] != ')') j++;
							while (s[j] == ' ') j++;
							Vcount++;
							if (s[j] == ')') break;
							j--;
						}
						else if (s[j] == '(') {	//매개변수가 또 다른 DEFUN을 포함하고있다면
							C.push_back('(');
							j++;
							while (!C.empty()) { //괄호를 통해 짝을 찾아 매개변수 값을 찾는다.
								if (s[j] == '(')
									C.push_back('(');
								else
									C.pop_back();
								j++;
							}
							Vcount++;
							if (s[j] == ')') break;
							j--;
						}
					}
					if (Vcount < limit) return -7; //만약 매개변수값이 적다면 에러메세지를 출력한다.
				}
		}
		else if (s[i] == '-' || (s[i] >= '0'&&s[i] <= '9')) {	//s[i]값이 음수 또는 양수의 숫자 값이라면
			if (s[i] == '-')
				if (s[i + 1] == '-')// '-' 문자가 반복되는지 확인한다.
					return -3; // -- 연속입력 에러를 뜻하는 -3을 return 한다.
			while (s[i] != ' ' && s[i] != ')'&& i < size) {//숫자값이 끝날 때 까지 i값을 더해준다.
				if (s[i] == '.')//숫자값을 구하는중에 실수를 뜻하는 '.'문자가 나오는지 확인한다.
					return -4;  // 발견됐을 시에 실수를 입력했다는 에러를 뜻하는 -4를 return 한다.
				i++;// 공백이나 ')'문자를 만날 때 까지 i값을 더하면서 숫자길이만큼 넘어간다.
			}
			i -= 1; //s[i] 가 )가 되어 파싱하는데 문제가 발생하지 않도록한다.
		}
	}
	if (V.size() > 0) {
		if (V[0] == ')')
			return -5;	// '('의 위치가 잘못됐다는 것을 의미하는 -5를 return 한다.
		else
			return -6;	// ')'의 위치가 잘못됐다는 것을 의미하는 -6을 return 한다.
	}
	return ret;	//에러가 발견되지않았다면 괄호 쌍의 수를 return 한다.
}

string Exception(int N) {
	if (N == -1) {
		return "오직 알파벳, \"-\", \"(\", \")\", / 만 입력할 수있습니다.";
	}
	else if (N == -2) {
		return "undefined.";
	}
	else if (N == -3) {
		return "\"-\"는 연속해서 입력할 수 없습니다.";
	}
	else if (N == -4) {
		return "숫자가 들어갈 자리에 정수가 아닌 실수가 입력되었습니다.";
	}
	else if (N == -5) {
		return "\")\"의 위치 또는 방향이 적절하지 않습니다.";
	}
	else if (N == -6) {
		return "\"(\"의 위치 또는 방향이 적절하지 않습니다.";
	}
	else if (N == -7) {
		return "매개변수가 맞지 않습니다.";
	}
	else if (N == 0) {
		return "괄호가 입력되지 않았습니다.";
	}
	else {
		return "Unkown Error";
	}
}

void retVar(string s, string defun,int j, int &i) { // DEFUN의 매개변수를 구해주는 함수이다.
	vector<char> C;
	if (j == 0) { // j==0이란 것은 첫번째 변수를 말한다.
		if (s[i] == '(')
			i++;
		if ((s[i] >= '0'&&s[i] <= '9') || s[i] == '-')
			;
		else
			i = s.find(' ', i); //정수값이 아니라면 ' ' 을 찾아준다.
	}
	while (s[i] == ' ') i++;
	if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-') { //매개변수가 만약 숫자라면
		int save = i;
		while (s[i] != ' ' && s[i] != ')') i++;	//공백이나 ')'문자를 만날 때 까지 j에 1을 더해준다.
		string p = s.substr(save, i - save);
		VM[M[defun].V[j]] = p; //현재 인덱스에 숫자값을 더해준다.
	}
	else { //또다른 DEFUN을 포함하고 있다면
		i = s.find('(', i); // 괄호의 시작을 찾아준다.
		int firstV = i;
		i++;
		C.push_back('(');
		while (!C.empty()) { //vector<char> C를통해 괄호의 짝을 찾아 매개변수를 찾아준다.
			if (s[i] == '(')
				C.push_back('(');
			else if (s[i] == ')')
				C.pop_back();
			i++;
		}
		int lastV = i;
		string k = s.substr(firstV, lastV - firstV);
		VM[M[defun].V[j]] = k; // 매개변수 Key를 가지고 있는 Map에다 해당하는 값을 넣어준다
	}
}

void CheckTimes(string &s) { //현재 문자열에서 TIMES에 대한 재귀의 진행여부를 결정한다.
	vector<char> C;
	int size = 0;
	int Tcount = 0, Tloc = 0;
	int flag = 0;
	size = s.size();
	for (int i = 0; i < (int)(s.size()); i++) { // s String길이 만큼 한번 진행한다.
		flag = 0;
		Tloc = s.find("TIMES", Tloc + 1); //TIMES DEFUN을 찾고
		if (Tloc < 0) break; //만약 존재하지않다면 바로 return 한다.
		i = Tloc;
		int Ssize = M["TIMES"].V.size(); // TIMES DEFUN의 매개변수 수를 저장한다.
		int saveF = i-1; // i-1의 위치를 기억해둔다
		for (int j = 0; j < Ssize; j++) { //매개변수 갯수만큼 찾기
			retVar(s, "TIMES", j, i); // 문자열 s에서 매개변수의 값을 가져온다.
			if (j == 0) { //만약 첫번째 변수라면
				if ((VM[M["TIMES"].V[j]][0] >= '0' && VM[M["TIMES"].V[j]][0] <= '9') || VM[M["TIMES"].V[j]][0] == '-') { //변수가 정수라면
					int V = atoi(VM[M["TIMES"].V[j]].c_str()); // string값을 정수로 변형
					if (V < 1)  //정수값이 1보다 작다면 재귀를 그만둬야 한다는 것을 의미한다.
						flag = 1; //2번째 변수를 구하고 끝내기 위한 신호
					else
						break; //0보다 크다면 재귀를 진행해야하므로 for문을 탈출하고 다음 TIMES가 있는지 확인하러간다.
				}
				else {//변수가 또다른 DEFUN을 포함하고있다면
					string val = Result(VM[M["TIMES"].V[j]], 1); // 이미 TIMES를 제외한 모든 DEFUN이 MINUS와 IF로 바뀌었기 때문에 Result함수를 진행하여
					int Val = atoi(val.c_str());				//첫번째 인자값을 구한다. 만약 인자값이 1보다 작다면 재귀함수를 멈춘다.
					if (Val < 1) {
						flag = 1;
					}
					else { //0보다 크다면 재귀를 진행해야하므로 for문을 탈출하고 다음 TIMES가 있는지 확인하러간다.
						break;
					}
				}
			}
			else if (j == 1) { //두번째 매개변수라면
				if (flag) { //만약 재귀함수를 멈춰야한다면
					i++;
					s.replace(saveF,i-saveF+1,"0"); // 첫번째 인자가 0보다 작으므로 그 값은 0으로 바뀐다.
					i = saveF; // 뒤에 TIMES가 존재하는지 확인해야 하므로 i값을 두번째 인자가 끝나는 위치로 바꿔준다.
				}
			}
		}
	}
}

void CheckString(string &s) { //모든 DEFUN들을 MINUS와 IF로 바꾸기위해 계속해서 진행한다.
	int Val = 1;
	while (Val) { // Val != 0 이면 계속진행
		Val = makeString(s); // TIMES함수가 몇개 존재하는지 return 한다.
		if(Val >0) // 만약 TIMES함수가 존재한다면
			CheckTimes(s); // makeString에서 Times체크
	}
}

int makeString(string &s) { //TIMES를 제외한(최초 1회는 실행) 모든 DEFUN을 MINUS와 IF로 바꿔준다.
	vector<char> C;
	int check = 1,Tcheck=0;
	int size = 0,First = 0;
	while (check) {
		size = s.size();
		check = 0;
		for (int i = 0; i < (int)(s.size()); i++) { //문자열 s.size()값을 받아와 문자열이 달라져도 길이만큼 계속 진행.
			if (s[i] == ' '|| (s[i] >= '0' && s[i] <='9') || s[i] == '-' || s[i] == ')') continue; //만약 공백, 정수, \')\'라면 건너뛴다.
			if (s[i] >= 'A' || s[i] <= 'Z') { //DEFUN이 시작하는 부분을 찾는다.
				int index = s.find(' ', i); //다음 공백위치를 찾아 DEFUN Name을 구한다.
				string defun = s.substr(i+1, index - i-1); // DEFUN Name을 구한다.
				if (defun.find('(') != -1) defun = defun.substr(1, defun.size() - 1); //Name에 필요없는 값을 제거
				if ((defun == "MINUS" || defun == "IF") || (defun == "TIMES"&&Tcheck > 0 && First)) { //MINUS 나 IF 또는 TIMES이지만
					i = index;																		//이미 한번 바뀌거나 모든 문자열을 지났을 떄를 확인한다
					continue;
				}
				else {
					if (defun == "TIMES") Tcheck++; //TIMES가 존재하는지 체크
					check++; //DEFUN이 체크됐을 때 다음번에 MINUS, IF가 아닌 다른 DEFUN이 존재 할 수 있으므로 다시한번 체크한다.
					string Schange = M[defun].func; // 해당 DEFUN의 식을 가져온다.
					int Ssize = M[defun].V.size();
					int saveF = i;
					for(int j=0;j<Ssize;j++){ //변수 갯수만큼 찾기
						retVar(s, defun, j, i); //매개변수를 지정해준다.
						int start = Schange.find(M[defun].V[j],0); //식 안에서 매개변수가 존재하는 위치를 확인한다.
						while (start > -1) { //만약 존재한다면 같은 매개변수를 갖는곳에 찾은 값을 대입한다.
							string p = VM[M[defun].V[j]];
							Schange.replace(start, M[defun].V[j].size(), p);
							start = Schange.find(M[defun].V[j], start+1); //다른 위치에도 변수가 존재하는지 확인한다.
						}
					}
					while (s[i] != ')') i++; //현재 DEFUN의 마지막 괄호를 잡아준다.
					s.replace(saveF, i - saveF + 1,Schange); // 현재 DEFUN의 시작, 끝 괄호까지의 값을 Schange값으로 바꿔준다.
					i = saveF + Schange.size()-1;
				}
			}
		}
		First++; //i = 0 ~ s.size() 까지 한번 돌았다는 체크.
	}
	return Tcheck; //TIMES함수의 개수를 return 한다.
}

int makeTree(int i, int index, string s) { // 문자열을 파싱하여 트리를 만드는 함수이다.
	int size = s.size();
	if (i > size) return i;//만약 i의값이 문자열의 크기보다 크다면 i값을 return 하여 함수를 종료시킨다.
	for (int j = i; j < size; j++) {	//반복문은 i부터 size까지 진행한다
		if (s[j] == '(' || s[j] == ' ') continue; //'('문자나 공백을 만나면 넘어간다.
		if (s[j] == 'M') { //'M'문자를 만났다는 것은 이미 에러를 검출한 후기 때문에 MINUS를 의미한다.
			Tree[index] = "MINUS";	//때문에 Tree에 operator로 MINUS값을 저장한다.
			j += 5;	//MINUS의 문자 길이만큼 더해준다.
			j = makeTree(j + 1, index * 2 + 1, s); //다시 makeTree()함수를 재귀호출하여 i=j+1부터 진행하고,
			index++;							   //index를 왼쪽자식을 뜻하는 index*2+1의 값을 인자로 넣어준다.
		}			//재귀호출을 마치고 돌아왔을 때는 현재 index의 형제노드에 값을 저장해야하므로 index+1을 해준다.
		else if (s[j] == 'I') { //'I'무자는 IF를 뜻한다.
			Tree[index] = "IF";	//현재 index에 IF를 저장한다.
			j += 2;	//IF의 길이만큼 더해준다.
			j = makeTree(j + 1, index * 2 + 1, s); //다시 makeTree()함수를 재귀호출하여 i=j+1부터 진행하고,
			index++;							   //index를 왼쪽자식을 뜻하는 index*2+1의 값을 인자로 넣어준다.
		}		//재귀호출을 마치고 돌아왔을 때는 현재 index의 형제노드에 값을 저장해야하므로 index+1을 해준다.
		else if (s[j] == '-' || (s[j] >= '0' && s[j] <= '9')) { // 음수나 양수가 입력됐을 시에는
			int save = j;
			while (s[j] != ' ' && s[j] != ')') j++;	//공백이나 ')'문자를 만날 때 까지 j에 1을 더해준다.
			j--; // ')'문자를 만났을 때 return 해야하기 때문에 j값을 -1해준다
			Tree[index] = s.substr(save, j - save + 1); //현재 인덱스에 숫자값을 더해준다.
			index++; //현재 index의 형제노드에 값을 저장해야하므로 index + 1을 해준다.
		}
		else if (s[j] == ')') { //')'문자를 만났을 때는 더이상 탐색할 형제노드가 없다는 것이다.
			return j; // j 값을 return 하며 현재 위치에서 벗어난다.
		}
	}
	return i;
}

void postorder(int index) {	//Postorder로 순회하기위한 재귀함수이다.
	if (Tree[index] == "\0") return;	//Tree[index]의 값이 "\0"이라면 함수를 return 한다.
	postorder(index * 2 + 1); //왼쪽자식노드를 먼저 탐색한다.
	postorder(index * 2 + 2); //다음으로 오른쪽 자식노드를 탐색한다.

	printS += Tree[index] + ' '; //출력 postorder값을 저장한다.

	if (Tree[index] == "MINUS") { //Tree[index] 값이 MINUS 라면 MINUS()함수를 호출하여 스택에 결과값 push
		Stack.push(MINUS());
	}
	else if (Tree[index] == "IF") {//Tree[index]값이 IF라면 IF()함수를 호출하여 스택에 결과값 push
		Stack.push(IF());
	}
	else { //둘다 아닐경우에는 숫자를 의미하므로 문자열을 숫자로 바꿔 스택에 push해준다.
		Stack.push(atoi(Tree[index].c_str()));
	}
}

int MINUS() {
	int b = Stack.top(); //top에 있는 값이 b
	Stack.pop();
	int a = Stack.top();// 그 다음있는 값이 a를 의미하고
	Stack.pop();
	a = a - b; //두값을 MINUS연산하여 return 한다.
	return a;
}

int IF() {
	int b = Stack.top();//top에 있는 값이 b
	Stack.pop();
	int a = Stack.top();//그 다음에 있는 값이 a를 의미하고
	Stack.pop();
	if (a <= 0) b = 0; // 만약 a가 양수가 아니라면 b=0
	return b;
}
