#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define WRITE(S) write(STDERR_FILENO, S, strlen(S))

static void handler(int signum) {
	switch (signum) {
		case SIGINT: // Console interrupt
			WRITE("Du machst die Nase traurig... :(\n");
			break;
		case SIGTERM:
			WRITE("Warum willst du die Nase loswerden? :(\n");
			break;
		default:
			WRITE("Die Nase ist unsterblich!\n");
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

	while (sleep(10) != 0) {}

	return EXIT_SUCCESS;
}
