/*This file is practice11 of Chapter1*/

#include <stdio.h>
#include <ctype.h>

int main(void){
	char	c, name[100];
	int	age, i, sum = 0;

	printf("\n What your name? ");
	for (i = 0; (c=getchar()) !='\n'; ++i){
		name[i] = c;
		if(isalpha(c))
			sum+=c;
	}
	name[i] = '\0';
	printf("\n How old are you? ");
	scanf("%d", &age);

	printf("\n%s %s, %s %d.\n", "Hello",
			name,
			"next year you will be",
			age + 1);
	return 0;
}


