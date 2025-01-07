/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macorso <maxence22corso@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:20:15 by macorso           #+#    #+#             */
/*   Updated: 2025/01/07 23:04:00 by macorso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_cmd	*lst_last(t_cmd *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_cmd	*lst_new(char *cmd_path, char **args)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->cmd_path = cmd_path;
	new->args = args;
	new->pid = 0;
	new->next = NULL;
	return (new);
}

void	lst_add_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = lst_last(*lst);
	last->next = new;
}

int	parse_cmds(t_pipex *pipex, int ac, char **av, int start)
{
	while (start < ac - 1)
	{
		lst_add_back(&pipex->cmd_list, lst_new(av[start], av + start));
		start++;
	}
	return (0);
}

void	print_cmds(t_cmd *lst)
{
	while (lst)
	{
		ft_putstr_fd("cmd_path: ", 1);
		ft_putendl_fd(lst->cmd_path, 1);
		ft_putstr_fd("args: ", 1);
		ft_putendl_fd(lst->args[0], 1);
		lst = lst->next;
	}
}

int main(int ac, char **av, char **envp)
{
	(void)envp;
	t_pipex	pipex;
	int		i;

	if (ac < 2)
	{
		ft_putstr_fd("Error: too few arguments\n", 2);
		return (1);
	}
	if (ac < 5)
	{
		ft_putstr_fd("Error: too few commands\n", 2);
		return (1);
	}
	if (!ft_strncmp(av[1], "here_doc", 8))
	{
		pipex.is_here_doc = true;
		pipex.limiter = av[2];
		i = 3;
	}
	else
	{
		pipex.is_here_doc = false;
		pipex.infile_fd = open(av[1], O_RDONLY);
		i = 2;
	}
	if (pipex.infile_fd == -1)
	{
		ft_putstr_fd("Error: failed to open input file\n", 2);
		pipex.infile_fd = open("/dev/null", O_RDONLY);
	}
	pipex.outfile_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex.outfile_fd == -1)
	{
		ft_putstr_fd("Error: failed to open output file\n", 2);
		return (1);
	}
	pipex.status = 0;
	pipex.cmd_list = NULL;
	if (parse_cmds(&pipex, ac, av, i) == 1)
	{
		ft_putstr_fd("Error: failed to parse commands\n", 2);
		return (1);
	}
	print_cmds(pipex.cmd_list);
	// if (exec_cmds(&pipex, envp) == 1)
	// {
	// 	ft_putstr_fd("Error: failed to execute commands\n", 2);
	// 	return (1);
	// }
	return (0);
}