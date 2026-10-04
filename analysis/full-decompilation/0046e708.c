
void FUN_0046e708(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  piVar2 = param_1;
  param_1 = (int *)((param_1[1] - *param_1) / 0x48);
  FUN_00464a5e(&param_1,1);
  iVar5 = piVar2[1];
  iVar1 = *piVar2;
  iVar3 = (iVar5 - iVar1) / 0x48 - (int)param_1;
  if (iVar3 < 0) {
    uVar4 = FUN_0046e184();
    FUN_0046e7f4(iVar5,(int)param_1 - (iVar5 - iVar1) / 0x48,uVar4);
  }
  else if (0 < iVar3) {
    FUN_0046e79a(iVar5 + iVar3 * -0x48,iVar5);
  }
  for (iVar5 = *piVar2; iVar5 != piVar2[1]; iVar5 = iVar5 + 0x48) {
    FUN_0046e1fa(param_2,param_3);
  }
  return;
}

