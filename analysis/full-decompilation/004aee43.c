
int __thiscall FUN_004aee43(char *param_1,char *param_2,char *param_3,char *param_4)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  
  iVar4 = FUN_004aeea6();
  if (0 < iVar4) {
    cVar1 = param_4[2];
    cVar2 = *param_4;
    cVar3 = *param_1;
    param_2[1] = param_4[1] - param_1[1];
    param_2[2] = cVar1;
    *param_2 = cVar2 - cVar3;
    if (iVar4 == 2) {
      cVar1 = param_1[3];
      cVar2 = param_4[1];
      cVar3 = param_4[2];
      *param_3 = *param_4 - param_1[2];
      param_3[1] = cVar2 - cVar1;
      param_3[2] = cVar3;
    }
  }
  return iVar4;
}

