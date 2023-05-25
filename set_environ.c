/**
 * _setenv - compares env variables names
 * with the name passed.
 * 
 * @shell_data: data relevant (env name and env value)
 * Return: 1 on success.
 */
int _setenv(data_shell *shell_data)
{
	if (shell_data->args[1] == NULL || shell_data->args[2] == NULL)
	{
		getError_Builtin(shell_data, -1);
		return (1);
	}
	set_env(shell_data->args[1], shell_data->args[2], shell_data);
	return (1);
}

/**
 * _unsetenv - deletes a environment variable
 * 
 * @shell_data: data relevant (env name)
 * Return: 1 on success.
 */
int _unsetenv(data_shell *shell_data)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int i, j, k;

	if (shell_data->args[1] == NULL)
	{
		getError_Builtin(shell_data, -1);
		return (1);
	}
	k = -1;
	for (i = 0; shell_data->_environ[i]; i++)
	{
		var_env = _strdup(shell_data->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, shell_data->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		getError_Builtin(shell_data, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; shell_data->_environ[i]; i++)
	{
		if (i != k)
		{
			realloc_environ[j] = shell_data->_environ[i];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(shell_data->_environ[k]);
	free(shell_data->_environ);
	shell_data->_environ = realloc_environ;
	return (1);
}
