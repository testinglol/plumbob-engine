
void FUN_00494f77(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  
  cVar1 = param_2[1];
  cVar2 = param_2[2];
  cVar3 = (&DAT_006e481d)[param_3 * 3];
  *param_1 = *param_2 + (&DAT_006e481c)[param_3 * 3];
  param_1[1] = cVar1 + cVar3;
  param_1[2] = cVar2;
  return;
}

