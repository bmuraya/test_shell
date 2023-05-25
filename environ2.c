#include "shell_header.h"

/**
 * set_env - sets an environment variable
 * 
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @shell_data: data structure (environ)
 * Return: no return
 */
void set_env(char *name, char *value, data_shell *shell_data)
{
	int i;
    
	char *var_env, *name_env;

	for (i = 0; shell_data->_environ[i]; i++)
	{
		var_env = _strdup(shell_data->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(shell_data->_environ[i]);
			shell_data->_environ[i] = copy_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	shell_data->_environ = relc_mem_db(shell_data->_environ, i, sizeof(char *) * (i + 2));
	shell_data->_environ[i] = copy_info(name, value);
	shell_data->_environ[i + 1] = NULL;
}
