#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h> //for exit

jmp_buf errorRecoveryJump;

void errorRecovery() {
	printf("Error!\n");
	longjmp(errorRecoveryJump,0);
	printf("You will never see this\n");
}

int main()
{
while(1) {
	if(setjmp(errorRecoveryJump)) {
		printf("Back to main\n");
		break;
	}
	else {
		errorRecovery();
	}
}
printf("Exited from the for loop\n");


return 0;
}