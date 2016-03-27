#include<stdio.h>
// 파일에 존재하는 알파벳들의 개수를 세는 함수이다.
// 인자로는 파일 포인터와 개수를 저장하는 배열을 받는다.
void NumOfAlphabet(FILE* fp,int NumOfChar[26]){
	char current;
	while(current!=EOF){
		current = fgetc(fp); // fp 파일 포인터에서 문자 하나를 가져온다.
		if(current>='a'&&current<='z')
			NumOfChar[current-'a']+=1;
		if(current>='A'&&current<='Z')
			NumOfChar[current-'A']+=1;
	}
}
int main(void){
	int NumOfChar[26] = {0,};
	FILE* fp;

	fp = fopen("text.txt","r");
	
	NumOfAlphabet(fp,NumOfChar);

	printf("a(A)%4d, b(B)%4d, c(C)%4d, d(D)%4d, e(E)%4d, f(F)%4d,\n",NumOfChar[0],NumOfChar[1],NumOfChar[2],NumOfChar[3],NumOfChar[4],NumOfChar[5]);
	printf("g(G)%4d, h(H)%4d, i(I)%4d, j(J)%4d, k(K)%4d, l(L)%4d,\n",NumOfChar[6],NumOfChar[7],NumOfChar[8],NumOfChar[9],NumOfChar[10],NumOfChar[11]); 
	printf("m(M)%4d, n(N)%4d, o(O)%4d, p(P)%4d, q(Q)%4d, r(R)%4d,\n",NumOfChar[12],NumOfChar[13],NumOfChar[14],NumOfChar[15],NumOfChar[16],NumOfChar[17]);
	printf("s(S)%4d, t(T)%4d, u(U)%4d, v(V)%4d, w(W)%4d, x(X)%4d,\n",NumOfChar[18],NumOfChar[19],NumOfChar[20],NumOfChar[21],NumOfChar[22],NumOfChar[23]); 
	printf("y(Y)%4d, z(Z)%4d,\n",NumOfChar[24],NumOfChar[25]);


	return 0;
}
