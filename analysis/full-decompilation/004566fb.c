
void FUN_004566fb(int *param_1)

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
    FUN_004564f0(iVar4,(int)param_1 - iVar2,&local_8);
  }
  else if (0 < iVar3) {
    FUN_0052ea87(iVar4 + iVar3 * -4,iVar4);
  }
  iVar4 = *piVar1;
  if (iVar4 != piVar1[1]) {
    iVar2 = iVar4 + 2;
    do {
      FUN_00464973(iVar2,1);
      FUN_00464973(iVar4,1);
      iVar4 = iVar4 + 4;
      iVar2 = iVar2 + 4;
    } while (iVar4 != piVar1[1]);
  }
  return;
}

