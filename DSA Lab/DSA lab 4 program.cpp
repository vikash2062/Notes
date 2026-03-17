#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value){
	if(top >= MAX - 1){
		printf("Stack overflow\n");
		return;
	}
	stack[++top] = value;
}

int pop(){
	if(top < 0){
		printf("Stack underflow\n");
		exit(1);
	}
	return stack[top--];
}

int evaluatePostfix(char* exp){
	int i = 0;
	
	while(exp[i] != '\0'){
		if (isdigit(exp[i])){
			push(exp[i] - '0');  
		} else {
			int val2 = pop();
			int val1 = pop();
			
			switch (exp[i]){
				case '+': push(val1 + val2); break;
				case '-': push(val1 - val2); break;
				case '*': push(val1 * val2); break;
				case '/': push(val1 / val2); break;
				default:
					printf("Invalid operator %c\n", exp[i]);
					exit(1);
			}
		}
		i++;
	}
	return pop();
}

int main(){
	char exp[] = "53+2*";  // (5 + 3) * 2 = 16
	char exp1[] = "53-2*";
	char exp2[] = "53*2*";
	char exp3[] = "53/2*";
	printf("Postfix Expression Evaluation: %d\n", evaluatePostfix(exp));
	printf("Postfix Expression Evaluation: %d\n", evaluatePostfix(exp1));
	printf("Postfix Expression Evaluation: %d\n", evaluatePostfix(exp2));
	printf("Postfix Expression Evaluation: %d\n", evaluatePostfix(exp3));
	return 0;
}

