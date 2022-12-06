#include "main.h"

/**
 * main - Main loop, recieve input from CLI parse and execute it
 * @argc: Number of arguments passed to the program
 * @argv: Array of arguments
 * Return: Always 0 on success
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	char **arguments = NULL;
	char *input_stdin = NULL;
	int status_return = 1, exit_status = 0;
	size_t size = 0;
	ssize_t n = 0; /* to check getline return value and EOF */

	/* check if we stay or exit in the loop */
	while (status_return && n != EOF) /* EOF has a value of -1, so it is an int */
	{
		size = 0; /* set to 0 in every new input */
		/* return 1 if the file in the argument refers to the terminal */
		status_return = isatty(STDIN_FILENO);
		if (status_return)
			write(STDOUT_FILENO, "dav_shell->$ ", 13); /* print the prompt to stdout */

		/* store the input_stdin string or check for EOF or any error */
		n = getline(&input_stdin, &size, stdin);
		if (n == -1) /* account for EOF or any error*/
		{
			free(input_stdin);
			break;
		}
		if (validate_spaces(input_stdin))
		{
			free(input_stdin);
			continue;
		}
		arguments = hsh_tokenizer(input_stdin);
		if (*arguments[0] == '\0')
			continue;
		status_return = hsh_execute_builtins(arguments, input_stdin,
				argv, &exit_status);
		free(input_stdin);
		free(arguments);
	}
	return (0);
}
