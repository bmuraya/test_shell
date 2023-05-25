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
