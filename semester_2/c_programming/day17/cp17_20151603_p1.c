#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char dept_name[25];
	int dept_no;
}dept;

enum Gender { Male = 0, Female };

typedef struct
{
	int employee_id;
	char name[40];
	enum Gender gender;
	dept department;
	double salary;
} employee_data;

int search(employee_data *e, int num, int keyword);
employee_data update(employee_data e, int n);

int main(void)
{
	FILE *fp = fopen("17_input.txt","r");

	int	number;
	char tmp_str[20];

	employee_data *employees;
	int user_input;
	int continue_flag;
	int i;

	if(fp == NULL)
	{
		puts("FILE OPEN ERROR");
		return 0;
	}

	fscanf(fp,"%d",&number);
	employees = malloc(sizeof(employee_data) * number);
	
	for(i = 0;i < number; ++i)
	{
		fscanf(fp,"%d / ",&employees[i].employee_id);
		fscanf(fp,"%[^/] / ",employees[i].name);

		fscanf(fp,"%s / ",tmp_str);
		employees[i].gender = strcmp(tmp_str,"Male") == 0 ? Male : Female;

		fscanf(fp,"%s / ",employees[i].department.dept_name);
		fscanf(fp,"%d / ",&employees[i].department.dept_no);

		fscanf(fp,"%lf",&employees[i].salary);
	}
	do
	{
		printf("Employee ID : ");
		scanf("%d",&user_input);
		i = search(employees, number, user_input);
		
		if( i + 1 == 0 ) 
			puts("No employee");
		else
		{
			puts("------Employee Data------");
			printf("%d / %s / %s / %s / %d / %.2lf\n",employees[i].employee_id,employees[i].name,employees[i].gender == Male ? "Male" : "Female",employees[i].department.dept_name,employees[i].department.dept_no,employees[i].salary);

			puts("------Update Information------");
			printf("Input the department number : ");
			scanf("%d",&user_input);
			employees[i] = update(employees[i], user_input);
		}
		getchar();
		printf("Continue? (y/n) : ");
		user_input = getchar();
	}while( user_input == 'y');

	fclose(fp);

	fp = fopen("17_input.txt","w+");
	fprintf(fp,"%d\n",number);
	for(i = 0;i < number; ++i)
		fprintf(fp,"%d / %s / %s / %s / %02d / %.0lf\n",employees[i].employee_id,employees[i].name,employees[i].gender == Male ? "Male" : "Female",employees[i].department.dept_name,employees[i].department.dept_no,employees[i].salary);

	fclose(fp);

	return 0;
}
int search(employee_data *e, int num, int keyword)
{
	int i;
	for(i = 0;i < num; ++i)
		if(e[i].employee_id == keyword) return i;
}
employee_data update(employee_data e, int n)
{
	switch(n)
	{
		case 1:
			e.department.dept_no = 1;
			strcpy(e.department.dept_name,"FINANCE");
			break;
		case 2:
			e.department.dept_no = 2;
			strcpy(e.department.dept_name,"SALES");
			break;
		case 3:
			e.department.dept_no = 3;
			strcpy(e.department.dept_name,"RESEARCH");
			break;
		case 4:
			e.department.dept_no = 4;
			strcpy(e.department.dept_name,"PLANNING");
			break;
	}

	return e;
}
