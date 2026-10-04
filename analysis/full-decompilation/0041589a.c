
void FUN_0041589a(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8;
  
  piVar1 = param_1;
  param_1 = (int *)((param_1[1] - *param_1) / 0xc);
  FUN_00464a5e(&param_1,1);
  iVar4 = piVar1[1];
  iVar2 = (iVar4 - *piVar1) / 0xc;
  iVar3 = iVar2 - (int)param_1;
  if (iVar3 < 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    FUN_00415989(iVar4,(int)param_1 - iVar2,&local_10);
  }
  else if (0 < iVar3) {
    FUN_00415939(iVar4 + iVar3 * -0xc,iVar4);
  }
  iVar4 = *piVar1;
  if (iVar4 != piVar1[1]) {
    iVar2 = iVar4 + 4;
    do {
      FUN_00464a5e(iVar4,1);
      FUN_00464a5e(iVar2,1);
      iVar4 = iVar4 + 0xc;
      iVar2 = iVar2 + 0xc;
    } while (iVar4 != piVar1[1]);
  }
  return;
}

