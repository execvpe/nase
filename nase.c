#include <signal.h> // sigaction(3), _NSIG
#include <stdio.h>  // prtinf(3)
#include <stdlib.h> // EXIT_SUCCESS
#include <string.h> // strlen(3)
#include <unistd.h> // write(2)

#define WRITE(STR) write(STDERR_FILENO, STR, strlen(STR))

static void handler(int signum) {
	switch (signum) {
		case SIGINT: // Console interrupt
			WRITE("\rDu machst die Nase traurig... :(\n");
			break;
		case SIGTERM:
			WRITE("\rWarum willst du die Nase loswerden? :(\n");
			break;
		default:
			WRITE("\rDie Nase ist unsterblich!\n");
	}
}

static struct sigaction ign = {
	.sa_handler = &handler,
	.sa_flags   = SA_RESTART,
};

int main(int argc, char **argv) {
	sigemptyset(&(ign.sa_mask));

	for (int i = 0; i < _NSIG; i++) {
		sigaction(i, &ign, NULL);
	}

	printf("%s\n", "                                           ");
	printf("%s\n", "                     .                     ");
	printf("%s\n", "                   ,&                      ");
	printf("%s\n", "                  ,&                       ");
	printf("%s\n", "                 ,&                        ");
	printf("%s\n", "                ,&                         ");
	printf("%s\n", "               ,&                          ");
	printf("%s\n", "              ,&                           ");
	printf("%s\n", "             ,&'                           ");
	printf("%s\n", "            ,&'                            ");
	printf("%s\n", "           ,&'                             ");
	printf("%s\n", "          ,&'                              ");
	printf("%s\n", "         ,&'                               ");
	printf("%s\n", "        ,&'                    ,           ");
	printf("%s\n", "        &'                      %          ");
	printf("%s\n", "       /(                        %         ");
	printf("%s\n", "       @(                        ||        ");
	printf("%s\n", "       \\|       ,.eee.__        _g         ");
	printf("%s\n", "        '&,,____ ^*&&@@@@@nasey@^          ");
	printf("%s\n", "            ^^^^^*a,                       ");
	printf("%s\n", "                   ^1                      ");
	printf("%s\n", "                                           ");

	while (sleep(30) != 0) {}

	return EXIT_SUCCESS;
}
