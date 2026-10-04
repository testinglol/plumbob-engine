
void __thiscall FUN_00455800(int *param_1,uint param_2,int *param_3,char *param_4)

{
  int *piVar1;
  int iVar2;
  int **ppiVar3;
  size_t sVar4;
  int *local_8;
  
  if ((uint)(param_1[1] - *param_1) < param_2) {
    local_8 = param_1;
    FUN_004064df();
  }
  local_8 = (int *)((param_1[1] - *param_1) - param_2);
  ppiVar3 = &local_8;
  if (param_3 <= local_8) {
    ppiVar3 = &param_3;
  }
  piVar1 = *ppiVar3;
  sVar4 = _strlen(param_4);
  if ((sVar4 == 0xffffffff) || (-sVar4 - 2 <= (uint)((param_1[1] - *param_1) - (int)piVar1))) {
    FUN_004018ec();
  }
  iVar2 = *param_1;
  sVar4 = _strlen(param_4);
  FUN_00455881(iVar2 + param_2,(int)piVar1 + param_2 + iVar2,param_4,param_4 + sVar4);
  return;
}

