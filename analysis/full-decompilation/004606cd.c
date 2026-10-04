
void FUN_004606cd(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 local_10 [12];
  
  piVar1 = param_1;
  iVar4 = param_1[1];
  iVar2 = (iVar4 - *param_1) / 0xc;
  param_1 = (int *)iVar2;
  FUN_00464a5e(&param_1,1);
  iVar3 = iVar2 - (int)param_1;
  if (iVar3 < 0) {
    FUN_00460a97(iVar4,(int)param_1 - iVar2,local_10);
  }
  else if (0 < iVar3) {
    FUN_004609a6(iVar4 + iVar3 * -0xc,iVar4);
  }
  iVar2 = piVar1[1];
  for (iVar4 = *piVar1; iVar4 != iVar2; iVar4 = iVar4 + 0xc) {
    FUN_00459244(param_2,param_3);
  }
  return;
}

