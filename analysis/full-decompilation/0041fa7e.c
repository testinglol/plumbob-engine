
void FUN_0041fa7e(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_10;
  undefined4 local_c;
  undefined2 local_8;
  
  piVar1 = param_1;
  param_1 = (int *)((param_1[1] - *param_1) / 0xc);
  FUN_00464a5e(&param_1,1);
  iVar4 = piVar1[1];
  iVar2 = (iVar4 - *piVar1) / 0xc;
  iVar3 = iVar2 - (int)param_1;
  if (iVar3 < 0) {
    local_10 = 0;
    local_c = 0;
    local_8 = 1;
    FUN_0041fbd7(iVar4,(int)param_1 - iVar2,&local_10);
  }
  else if (0 < iVar3) {
    FUN_0041fb0c(iVar4 + iVar3 * -0xc,iVar4);
  }
  for (iVar4 = *piVar1; iVar4 != piVar1[1]; iVar4 = iVar4 + 0xc) {
    FUN_0041f333(param_2,param_3);
  }
  return;
}

