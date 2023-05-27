#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
<<<<<<< HEAD
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
=======
				show_str(av[0]);
				show_str(": 0: Can't open ");
				show_str(av[1]);
				write_history('\n');
				write_str(BUF_FLUSH);
>>>>>>> f5a7c7b22aee15e07cb983145cc865b77bf1b4ef
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
<<<<<<< HEAD
	populate_env_list(info);
	read_history(info);
=======
	pop_env_list(info);
	get_history_file(info);
>>>>>>> f5a7c7b22aee15e07cb983145cc865b77bf1b4ef
	hsh(info, av);
	return (EXIT_SUCCESS);
}
