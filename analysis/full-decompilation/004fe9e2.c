
void FUN_004fe9e2(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  uVar2 = param_2;
  piVar3 = param_1;
  if ((uint)(param_1[1] - *param_1) < param_2) {
    FUN_004064df();
  }
  iVar1 = *piVar3;
  param_1 = (int *)((piVar3[1] - iVar1) - uVar2);
  piVar3 = (int *)&param_1;
  if (param_3 <= param_1) {
    piVar3 = (int *)&param_3;
  }
  FUN_00412d8a(iVar1 + uVar2,*piVar3 + iVar1 + uVar2);
  return;
}

