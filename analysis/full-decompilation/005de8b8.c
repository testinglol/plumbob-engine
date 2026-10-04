
undefined4 __thiscall FUN_005de8b8(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = param_2;
  param_2 = (int *)*param_2;
  if (*param_3 <= (int)param_2) {
    param_2 = (int *)*param_3;
  }
  *param_1 = (int)param_2;
  iVar4 = piVar1[1];
  if (param_3[1] <= piVar1[1]) {
    iVar4 = param_3[1];
  }
  param_1[1] = iVar4;
  iVar5 = piVar1[2];
  if (piVar1[2] <= param_3[2]) {
    iVar5 = param_3[2];
  }
  param_1[2] = iVar5;
  iVar2 = piVar1[3];
  if (piVar1[3] <= param_3[3]) {
    iVar2 = param_3[3];
  }
  param_1[3] = iVar2;
  if ((param_2 == (int *)iVar5) || (iVar4 == iVar2)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

