#include <stdio.h>
#include <stdlib.h>

typedef struct s_env
{
	6 »···int»»···»···xK;
	7 »···int»»···»···yK;
	8 »···char»···»···**map;
	9 »···int»»···»···size;
	10 }»··»···»···»···t_env;
	11
	12 int ft_strlen(char *str)
	13 {
		14 »···int i = 0;
		15
		16 »···while (str[i])
		17 »···»···++i;
		18 »···return i;
		19 }
		20
		21 void print_map(char **map)
		22 {
			23 »···for (int i = 0; map[i]; ++i)
			24 »···»···printf("%s\n", map[i]);
			25 }
			26
			27 void find_king(t_env *env)
			28 {
				29 »···for (int i = 0; env->map[i]; ++i)
				30 »···{
					31 »···»···for (int j = 0; env->map[i][j]; ++j)
					32 »···»···{
						33 »···»···»···if (env->map[i][j] == 'K')
						34 »···»···»···{
							35 »···»···»···»···env->xK = i;
							36 »···»···»···»···env->yK = j;
							37 »···»···»···»···return ;
							38 »···»···»···}
							39 »···»···}
							40 »···}
							41 }
							42
							43 void solve(char **map, int xK, int yK)
							44 {
								45 »···int state = 1;
								46
								47 »···if (map[xK+1][yK+1] == 'P' || map[xK-1][xK-1] == 'P')
								48 »···»···state = 0;
								>> 49 »···for (int i = 0; i < yK; ++i)
								50 »···{
									51 »···»···if (map[xK][i] == 'R' || map[xK][i] == 'Q')
									52 »···»···»···state = 0;
									53 »···»···if (map[xK][i] == 'R' || map[xK][i] == 'Q')
									54 »···}
									>> 55 }
									56
									57 int main(int argc, char **argv)
									58 {
										59 »···int size;
										60 »···t_env env;
										61 »···if (argc > 1)
										62 »···{
											63 »···»···env.size = argc - 1;
											64 »···»···env.map = (char**)malloc(sizeof(char*) * argc);
											65 »···»···env.map[argc - 1] = NULL;
											66 »···»···for (int i = 0; i < argc - 1; ++i)
											67 »···»···{
												68 »···»···»···size = ft_strlen(argv[i + 1]);
												69 »···»···»···env.map[i] = (char*)malloc(sizeof(char*) * size + 1);
												70 »···»···»···for (int j = 0; j < size; ++j)
												71 »···»···»···»···env.map[i][j] = argv[i + 1][j];
												72 »···»···»···env.map[i][size] = '\0';
												73 »···»···}
												74 »···»···print_map(env.map);
												75 »···»···find_king(&env);
												76 »···»···printf("xK = %d yK = %d\n", env.xK, env.yK);
												77 »····solve(env.map, env.xK, env.yK);
												}
											}
