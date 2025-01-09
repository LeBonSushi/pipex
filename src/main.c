/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macorso <macorso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:20:15 by macorso           #+#    #+#             */
/*   Updated: 2025/01/09 15:52:25 by macorso          ###   ########.fr       */
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

char	*get_cmd_path(char *cmd, char **env_path)
{
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	if (!ft_strncmp(cmd, "/", 1) || !ft_strncmp(cmd, "./", 2) || !ft_strncmp(cmd, "../", 3))
		return (ft_strdup(cmd));
	while (env_path[i])
	{
		tmp = ft_strjoin(env_path[i], "/");
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

int	check_args(int ac, char **av, t_pipex **pipex)
{
	*pipex = malloc(sizeof(t_pipex));
	if (!*pipex)
	{
		ft_putendl_fd("Pipex Malloc failed", 2);
		exit(EXIT_FAILURE);
	}
	(*pipex)->cmd_list = NULL;
	(*pipex)->cmd_list = malloc(sizeof(t_cmd));
	if (!(*pipex)->cmd_list)
	{
		ft_putendl_fd("Command list malloc failed", 2);
		exit(EXIT_FAILURE);
	}
	if (!ft_strncmp(av[1], "here_doc", 8))
	{
		(*pipex)->outfile_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		(*pipex)->is_here_doc = true;
		(*pipex)->limiter = av[2];
	}
	else
	{
		(*pipex)->infile_fd = open(av[1], O_RDONLY);
		if ((*pipex)->infile_fd < 0)
		{
			(*pipex)->infile_fd = open("/dev/null", O_RDONLY);
			if ((*pipex)->infile_fd < 0)
			{
				ft_putendl_fd("La c'est la merde ya rien qui s'ouvre", 2);
				exit(EXIT_FAILURE);
			}
		}
		(*pipex)->outfile_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		(*pipex)->is_here_doc = false;
	}
	
}

int main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;
	if (ac < 2)
	{
		ft_putstr_fd("./pipex <infile> cmd cmd <outfile>", 2);
		exit(EXIT_SUCCESS);
	}
	if (!check_args(ac, av, &pipex))
	{
		
	}
}
