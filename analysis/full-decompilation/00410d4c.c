
void FUN_00410d4c(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_8;
  
  piVar1 = param_1;
  param_1 = (int *)(param_1[1] - *param_1 >> 2);
  FUN_00464a5e(&param_1,1);
  iVar4 = piVar1[1];
  iVar2 = iVar4 - *piVar1 >> 2;
  iVar3 = iVar2 - (int)param_1;
  if (iVar3 < 0) {
    local_8 = 0;
    FUN_00410e42(iVar4,(int)param_1 - iVar2,&local_8);
  }
  else if (0 < iVar3) {
    FUN_0042ed71(iVar4 + iVar3 * -4,iVar4);
  }
  for (iVar4 = *piVar1; iVar4 != piVar1[1]; iVar4 = iVar4 + 4) {
    FUN_00464a5e(iVar4,1);
  }
  return;
}

