#include<stdio.h>
int main(void){
	// 선언부
	FILE *ifp = fopen("input32.txt","r");
	FILE *ofp = fopen("output32.txt","w");
	float number1,number2,answer;
	char operator,equal;
	// 파일 열기 검사
	if(ifp == NULL) return 1;
	if(ofp == NULL) return 1;
	// 실행부
	while(1){
		fscanf(ifp,"%f %c %f %c %f",&number1,&operator,&number2,&equal,&answer);
		if(feof(ifp)) break; // 파일포인터가 EOF를 만나면 loop을 탈출한다.
		fprintf(ofp,"%.2f %c %.2f = %.2f ",number1,operator,number2,answer);
		// 각각 사칙연산에 맞게 계산되었는지 확인한다.
		if(operator == '+'){
			if(number1+number2 == answer)
				fprintf(ofp,"correct\n");
			else
				fprintf(ofp,"incorect\n");
		}
		if(operator == '-'){
			if(number1-number2 == answer)
				fprintf(ofp,"correct\n");
			else
				fprintf(ofp,"incorect\n");
		}
		if(operator == '*'){
			if(number1*number2 == answer)
				fprintf(ofp,"correct\n");
			else
				fprintf(ofp,"incorect\n");
		}
		if(operator == '/'){
			if(number1/number2 == answer)
				fprintf(ofp,"correct\n");
			else
				fprintf(ofp,"incorect\n");
		}	
		if(operator == '%'){
			if((int)number1%(int)number2 == answer)
				fprintf(ofp,"correct\n");
			else
				fprintf(ofp,"incorect\n");
		}	

	}
	// 스트림을 닫는다.
	fclose(ifp);
	fclose(ofp);
	return 0;
}

