
char * FUN_00494e66(char *param_1,char param_2,char *param_3)

{
  char cVar1;
  char cVar2;
  
  cVar1 = param_3[1];
  cVar2 = *param_3;
  param_1[2] = param_3[2];
  *param_1 = cVar2 * param_2;
  param_1[1] = cVar1 * param_2;
  return param_1;
}

