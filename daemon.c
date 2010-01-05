/**
 * daemon application in linux
 *
 * @date 20090731
 * @ref http://www.netzmafia.de/skripten/unix/linux-daemon-howto.html
 */

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/stat.h>

void daemonize()
{
	// Our process id and session id
	pid_t pid, sid;

	// Fork off the parent process
	pid = fork();
	if (pid < 0) { // Fork error
		exit(EXIT_FAILURE);
	}
	if (pid > 0) { // Fork OK, then exit the parent process
		exit(EXIT_SUCCESS);
	}

	// Change the file mode mask
	umask(0);

	// Open any logs here

	// Create a new SID for the child process
	sid = setsid();
	if (sid < 0) {
		// Log failure
		exit(EXIT_FAILURE);
	}

	// Change the current working directory
	if (chdir("/") < 0) {
		// Log failure
		exit(EXIT_FAILURE);
	}

	// Close out the standard file descriptors
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	// Daemon-specific initialization goes here
}

int main(int argc, char* argv[])
{
	daemonize();

	// The big loop
	while (1) {
		// Do some task here
		sleep(30); // Wait 30 seconds
	}

	return EXIT_SUCCESS;
}
