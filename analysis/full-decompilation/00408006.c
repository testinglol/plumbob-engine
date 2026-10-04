
void FUN_00408006(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  piVar2 = param_1;
  param_1 = (int *)(param_1[1] - *param_1 >> 5);
  FUN_00464a5e(&param_1,1);
  iVar5 = piVar2[1];
  iVar1 = *piVar2;
  iVar3 = (iVar5 - iVar1 >> 5) - (int)param_1;
  if (iVar3 < 0) {
    uVar4 = FUN_0040808c();
    FUN_004082fc(iVar5,(int)param_1 - (iVar5 - iVar1 >> 5),uVar4);
  }
  else if (0 < iVar3) {
    FUN_0040812f(iVar5 + iVar3 * -0x20,iVar5);
  }
  for (iVar5 = *piVar2; iVar5 != piVar2[1]; iVar5 = iVar5 + 0x20) {
    FUN_00407b36(param_2,param_3);
  }
  return;
}

