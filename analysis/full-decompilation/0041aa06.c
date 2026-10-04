
void FUN_0041aa06(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  piVar2 = param_1;
  param_1 = (int *)((param_1[1] - *param_1) / 0x5c);
  FUN_00464a5e(&param_1,1);
  iVar5 = piVar2[1];
  iVar1 = *piVar2;
  iVar3 = (iVar5 - iVar1) / 0x5c - (int)param_1;
  if (iVar3 < 0) {
    uVar4 = FUN_00418ce5();
    FUN_0041b085(iVar5,(int)param_1 - (iVar5 - iVar1) / 0x5c,uVar4);
  }
  else if (0 < iVar3) {
    FUN_0041af11(iVar5 + iVar3 * -0x5c,iVar5);
  }
  for (iVar5 = *piVar2; iVar5 != piVar2[1]; iVar5 = iVar5 + 0x5c) {
    FUN_00418b8f(param_2,param_3);
  }
  return;
}

