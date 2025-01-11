/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macorso <macorso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:20:15 by macorso           #+#    #+#             */
/*   Updated: 2025/01/11 01:07:53 by macorso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char **get_env(char **envp)
{
	char **env_path;

	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH=", 5))
		{
			env_path = ft_split(*envp + 5, ':');
			if (!env_path)
				return (NULL);
			return (env_path);
		}
		envp++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **envp_path)
{
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	if (!cmd)
		return (NULL);
	if (!ft_strncmp(cmd, "/", 1) || !ft_strncmp(cmd, "./", 2) || !ft_strncmp(cmd, "../", 3))
		return (ft_strdup(cmd));
	while (envp_path[i])
	{
		tmp = ft_strjoin(envp_path[i], "/");
		if (!tmp)
			return (NULL);
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!path)
			return (NULL);
		if (!access(path, F_OK | X_OK))
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

void	free_cmds(t_cmd	*cmd)
{
	t_cmd	*next;
	if (!cmd)
		return ;
	while (cmd)
	{
		next = cmd->next;
		free(cmd);
		cmd = next;
	}
}

void	free_lst(t_pipex *pipex)
{
	if (!pipex)
		return ;
	if (pipex->cmd_list)
		free_cmds(pipex->cmd_list);
	
}

void	print_pipex(t_pipex *pipex)
{
	printf("is_here_doc: %s\ninfile_fd: %d\noutfile_fd: %d\nlimiter: %s\n", pipex->is_here_doc ? "true":"false", pipex->infile_fd, pipex->outfile_fd, pipex->limiter);
}

t_cmd *lst_new(char *av, char **envp)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->args = ft_split(av, ' ');
	new->cmd_path = get_cmd_path(new->args[0], get_env(envp));
	new->next = NULL;
	return (new);
}

t_cmd	*lst_last(t_cmd *cmd)
{
	while (cmd && cmd->next)
	{
		cmd = cmd->next;
	}
	return (cmd);
}

void	lst_addback(t_cmd **cmds, t_cmd *new)
{
	t_cmd	*last;

	if (cmds)
	{
		if (*cmds)
		{
			last = lst_last(*cmds);
			last->next = new;
		}
		else
			*cmds = new;
	}
}

void	print_args(char **args)
{
	int	i;

	i = 0;
	printf("Args: ");
	while (args[i])
	{
		printf("%s", args[i]);
		i++;
	}
	printf("\n");
}

void	print_list(t_cmd *cmd)
{
	while (cmd)
	{
		print_args(cmd->args);
		printf("cmd_path: %s\n", cmd->cmd_path);
		printf("pid: %d\n", cmd->pid);
		cmd = cmd->next;
	}
}

// int	check_args(int ac, char **av, char **envp, t_pipex **pipex)
// {
// 	char	*line;
// 	int		i;
// 	int		cmd_nb;


// 	i = 0;
// 	cmd_nb = 0;
// 	*pipex = malloc(sizeof(t_pipex));
// 	if (!*pipex)
// 	{
// 		ft_putendl_fd("Pipex Malloc failed", 2);
// 		exit(EXIT_FAILURE);
// 	}
// 	if (!ft_strncmp(av[1], "here_doc", 8))
// 	{
// 		(*pipex)->infile_fd = open(HERE_DOC, O_WRONLY | O_CREAT | O_APPEND, 0777);
// 		if ((*pipex)->infile_fd < 0)
// 			return (ft_putendl_fd("Couldn't open infile", 2), 0);
// 		(*pipex)->outfile_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
// 		if ((*pipex)->outfile_fd < 0)
// 			return (ft_putendl_fd("Couldn't open outfile", 2), 0);
// 		(*pipex)->is_here_doc = true;
// 		(*pipex)->limiter = av[2];
// 		while (1)
// 		{
// 			ft_putstr_fd("here_doc > ", 1);
// 			line = get_next_line(0);
// 			if (!ft_strncmp(line, (*pipex)->limiter, ft_strlen((*pipex)->limiter)))
// 			{
// 				free(line);
// 				break ;
// 			}
// 			ft_putstr_fd(line, (*pipex)->infile_fd);
// 			free(line);
// 		}
// 		close((*pipex)->infile_fd);
// 		(*pipex)->infile_fd = open(HERE_DOC, O_RDONLY);
// 		if ((*pipex)->infile_fd < 0)
// 			return (ft_putendl_fd("Couldn't open infile", 2), 0);
// 	}
// 	else
// 	{
// 		(*pipex)->infile_fd = open(av[1], O_RDONLY);
// 		if ((*pipex)->infile_fd < 0)
// 		{
// 			(*pipex)->infile_fd = open("/dev/null", O_RDONLY);
// 			if ((*pipex)->infile_fd < 0)
// 				return (ft_putendl_fd("La c'est la merde ya rien qui s'ouvre", 2), 0);
// 		}
// 		(*pipex)->outfile_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
// 		if ((*pipex)->outfile_fd < 0)
// 			return (ft_putendl_fd("Couldn't open outfile", 2), 0);
// 		(*pipex)->is_here_doc = false;
// 	}
// 	i = 2 + (*pipex)->is_here_doc;
// 	while (i < ac - 1)
// 	{
// 		lst_addback(&(*pipex)->cmd_list, lst_new(av[i], envp));
// 		i++;
// 		cmd_nb++;
// 	}
// 	(*pipex)->cmd_nb = cmd_nb;
// 	print_list((*pipex)->cmd_list);
// 	return (1);
// }

int exec_cmds(t_pipex *pipex, int ac, char **av,  char **envp)
{
	int		fd[2];
	t_cmd	*cmd;
	int		infile_fd;
	int		outfile_fd;
	int		i;
	
	cmd = pipex->cmd_list;
	i = 0;
	infile_fd = open(av[1], O_RDONLY);
	if (infile_fd < 0)
	{
		ft_putstr_fd("Couldn't open infile", 2);
		infile_fd = open("/dev/null", O_RDONLY);
		if (infile_fd < 0)
			return (ft_putstr_fd("Couldn't open infile", 2), 0);
	}
	outfile_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile_fd < 0)
	{
		ft_putstr_fd("Couldn't open outfile", 2);
		return (0);
	}
	while (cmd)
	{
		if (pipe(fd) < 0)
			return (ft_putstr_fd("Couldn't pipe", 2), 0);
		cmd->pid = fork();
		if (cmd->pid < 0)
			return (ft_putstr_fd("Couldn't fork", 2), 0);
		if (cmd->pid == 0)  // Child process
		{
			// Handle the first command
			if (i == 0)
			{
				dup2(infile_fd, STDIN_FILENO);  // Get input from infile
				dup2(fd[1], STDOUT_FILENO);    // Send output to pipe
			}
			// Handle the last command
			else if (i == pipex->cmd_nb - 1)
			{
				close(fd[1]);
				dup2(fd[0], STDIN_FILENO);     // Get input from pipe
				dup2(outfile_fd, STDOUT_FILENO); // Write output to outfile
			}
			// Handle middle commands
			else
			{
				close(fd[1]);
				dup2(fd[0], STDIN_FILENO);     // Get input from previous pipe
				dup2(fd[1], STDOUT_FILENO);    // Send output to next pipe
				close(infile_fd);
			}

			// Close pipe ends in child process
			close(fd[0]);
			close(fd[1]);

			// Check if the command exists and execute it
			if (!cmd->cmd_path)
			{
				ft_putstr_fd("Error: command not found: ", 2);
				ft_putstr_fd(cmd->args[0], 2);
				exit(127);
			}

			// Execute the command
			if (execve(cmd->cmd_path, cmd->args, envp) == -1)
			{
				ft_putstr_fd("Error: couldn't execute command: ", 2);
				ft_putstr_fd(cmd->args[0], 2);
				exit(127);
			}
		}
		else
		{
			// Close pipe ends in parent process
			close(fd[0]);
			close(fd[1]);
		}
		cmd = cmd->next;
		i++;
	}
	cmd = pipex->cmd_list;
	while (cmd)
	{
		waitpid(cmd->pid, &pipex->status, 0);
		cmd = cmd->next;
	}
	
	return (1);
}

int	open_file(char *file, int mode)
{
	int	fd;

	if (mode == 0)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (mode == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else
		fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Couldn't open file: ", 2);
		ft_putstr_fd(file, 2);
	}
	return (fd);
}
void	test()
{
	static int test = 0;
	ft_putstr_fd("test: ", 2);
	ft_putnbr_fd(test, 2);
	ft_putchar_fd('\n', 2);
	test++;
}

int main(int ac, char **av, char **envp)
{
    int     i;
    int     infile_fd;
    int     outfile_fd;
    int     cmd_counter;
    int     *pid;
    int     fd[2];
    int     status;
    char    **args;
    char    *cmd_path;

    if (ac < 5)
    {
        ft_putstr_fd("./pipex <infile> cmd cmd <outfile>", 2);
        return (0);
    }

    cmd_counter = 0;
	status = 0;
    pid = malloc(sizeof(int) * (ac - 3));

    if (!pid)
		return (ft_putstr_fd("Couldn't malloc", 2), 0);
    if (!ft_strncmp(av[1], "here_doc", 8)) // Handle here_doc
    {
        i = 3;
        outfile_fd = open_file(av[ac - 1], 0);
		test();
    }
    else // Normal command pipeline
    {
        i = 2;
        outfile_fd = open_file(av[ac - 1], 1);
        infile_fd = open_file(av[1], 2);
        dup2(infile_fd, STDIN_FILENO);
		close(infile_fd);
		test();
    }

    // Loop through commands and create child processes
    while (i < ac - 1)
    {
        if (pipe(fd) == -1)
        {
            ft_putstr_fd("Couldn't pipe", 2);
            return (0);
        }

        pid[cmd_counter] = fork();
        if (pid[cmd_counter] == -1)
        {
            ft_putstr_fd("Couldn't fork", 2);
            return (0);
        }

        if (pid[cmd_counter] == 0) // Child process
        {
			ft_putstr_fd("Child process\n", 2);
            args = ft_split(av[i], ' ');
            cmd_path = get_cmd_path(args[0], get_env(envp));

            if (!args[0] || !cmd_path)
            {
                ft_putstr_fd("Error: command not found: ", 2);
                ft_putstr_fd(args[0], 2);
                exit(127);
            }

			test();
            if (access(cmd_path, F_OK | X_OK))
            {
				test();
                ft_putstr_fd("Error: permission: ", 2);
                ft_putstr_fd(args[0], 2);
                exit(127);
            }

            // Handle input/output redirection for each command
            if (i == 2)
            {
				infile_fd = open(av[1], O_RDONLY);
                if (infile_fd < 0)
                {
                    ft_putstr_fd("Couldn't open infile", 2);
                    return (0);
                }
                dup2(infile_fd, STDIN_FILENO);
                dup2(fd[1], STDOUT_FILENO);
                close(infile_fd);
				ft_printf("debut commande\n");
            }
			else if (i == ac - 2)
			{
				outfile_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
				if (outfile_fd < 0)
				{
					ft_putstr_fd("Couldn't open outfile", 2);
					return (0);
				}
				dup2(fd[0], STDIN_FILENO);
				dup2(outfile_fd, STDOUT_FILENO);
				close(outfile_fd);
				ft_printf("fin commande\n");
			}
			else
			{
				dup2(fd[0], STDIN_FILENO);
				dup2(fd[1], STDOUT_FILENO);
				ft_printf("milieu commande\n");
			}
            execve(cmd_path, args, envp);
            ft_putstr_fd("Error: couldn't execute command: ", 2);
            ft_putstr_fd(args[0], 2);
			free(cmd_path);
			free(args);
            exit(127);
        }
		ft_putstr_fd("Parent process\n", 2);
		close(fd[0]);
		close(fd[1]);
        cmd_counter++;
        i++;
    }
	close(outfile_fd);

    // Wait for all child processes to finish
    cmd_counter = 0;
    while (cmd_counter < ac - 3)
    {
        waitpid(pid[cmd_counter], &status, 0);
        cmd_counter++;
    }

    free(pid);
    return (0);
}
