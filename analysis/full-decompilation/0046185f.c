
void __thiscall FUN_0046185f(char *param_1,char *param_2,char *param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  
  cVar1 = param_1[1];
  cVar2 = param_3[1];
  cVar3 = *param_3;
  cVar4 = *param_1;
  param_2[2] = param_1[2];
  *param_2 = cVar3 + cVar4;
  param_2[1] = cVar2 + cVar1;
  return;
}

