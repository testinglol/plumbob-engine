
void FUN_004a3192(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_c [2];
  
  piVar1 = param_1;
  param_1 = (int *)(param_1[1] - *param_1 >> 3);
  FUN_00464a5e(&param_1,1);
  iVar4 = piVar1[1];
  iVar2 = iVar4 - *piVar1 >> 3;
  iVar3 = iVar2 - (int)param_1;
  if (iVar3 < 0) {
    local_c[0] = 0;
    FUN_004a3312(iVar4,(int)param_1 - iVar2,local_c);
  }
  else if (0 < iVar3) {
    FUN_004a1827(iVar4 + iVar3 * -8,iVar4);
  }
  for (iVar4 = *piVar1; iVar4 != piVar1[1]; iVar4 = iVar4 + 8) {
    FUN_004a34e2(param_2,param_3);
  }
  return;
}

