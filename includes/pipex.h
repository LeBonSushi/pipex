/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macorso <maxence22corso@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:18:31 by macorso           #+#    #+#             */
/*   Updated: 2025/01/07 22:52:17 by macorso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "../libft/libft.h"

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/wait.h>
# include <stdbool.h>

typedef struct	s_cmd
{
	char		*cmd_path;
	char		**args;
	pid_t		pid;
	struct s_cmd	*next;
}			t_cmd;


typedef struct	s_pipex
{
	bool	is_here_doc;
	int		infile_fd;
	int		outfile_fd;
	char	*limiter;
	int		status;
	t_cmd	*cmd_list;
}			t_pipex;

#endif