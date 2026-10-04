
void __thiscall FUN_005f2e1e(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  if (param_3 == iVar1) {
    iVar1 = param_1[3];
    param_2[1] = param_1[4];
    *param_2 = iVar1 + -2;
    return;
  }
  iVar2 = param_1[3];
  if ((iVar1 < param_3) && (param_3 < param_1[1] + iVar1)) {
    param_3 = param_3 - iVar1;
  }
  else {
    if (param_1[6] - param_1[5] >> 2 == 0) goto LAB_005f2e71;
    param_3 = param_1[6] - param_1[5] >> 2;
  }
  iVar2 = iVar2 + *(int *)(param_1[5] + -4 + param_3 * 4);
LAB_005f2e71:
  param_2[1] = param_1[4];
  *param_2 = iVar2;
  return;
}

