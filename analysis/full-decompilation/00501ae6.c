
void FUN_00501ae6(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != param_2) {
    iVar2 = 0;
    for (iVar1 = param_2 - param_1 >> 2; iVar1 != 1; iVar1 = iVar1 >> 1) {
      iVar2 = iVar2 + 1;
    }
    FUN_00501b9e(param_1,param_2,0,iVar2 * 2,param_3);
    FUN_00501c21(param_1,param_2,param_3);
  }
  return;
}

