
void __thiscall FUN_00593864(int *param_1,uint param_2,uint param_3,char *param_4)

{
  int iVar1;
  uint uVar2;
  size_t sVar3;
  int *piVar4;
  
  uVar2 = param_2;
  if ((uint)(param_1[1] - *param_1) < param_2) {
    FUN_004064df();
  }
  piVar4 = (int *)&param_2;
  param_2 = (param_1[1] - *param_1) - uVar2;
  if (param_3 <= param_2) {
    piVar4 = (int *)&param_3;
  }
  iVar1 = *param_1 + uVar2;
  sVar3 = _strlen(param_4);
  FUN_0043017f(iVar1,iVar1 + *piVar4,param_4,param_4 + sVar3);
  return;
}

