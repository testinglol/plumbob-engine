
void FUN_0041187d(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 local_58 [84];
  
  piVar1 = param_1;
  param_1 = (int *)((param_1[1] - *param_1) / 0x54);
  FUN_00464a5e(&param_1,1);
  iVar4 = piVar1[1];
  iVar2 = (iVar4 - *piVar1) / 0x54;
  iVar3 = iVar2 - (int)param_1;
  if (iVar3 < 0) {
    FUN_00411951(iVar4,(int)param_1 - iVar2,local_58);
  }
  else if (0 < iVar3) {
    FUN_004118fa(iVar4 + iVar3 * -0x54,iVar4);
  }
  for (iVar4 = *piVar1; iVar4 != piVar1[1]; iVar4 = iVar4 + 0x54) {
    FUN_00411484(param_2,param_3);
  }
  return;
}

