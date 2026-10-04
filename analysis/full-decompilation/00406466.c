
int * __thiscall FUN_00406466(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  uVar2 = param_2;
  if ((uint)(param_1[1] - *param_1) < param_2) {
    FUN_004064df();
  }
  iVar1 = *param_1;
  param_2 = (param_1[1] - iVar1) - uVar2;
  piVar3 = (int *)&param_2;
  if (param_3 <= param_2) {
    piVar3 = (int *)&param_3;
  }
  FUN_004064ae(iVar1 + uVar2,*piVar3 + iVar1 + uVar2);
  return param_1;
}

