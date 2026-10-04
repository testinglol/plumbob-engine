
void FUN_005347f1(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != param_2) {
    iVar2 = 0;
    for (iVar1 = (param_2 - param_1) / 0x28; iVar1 != 1; iVar1 = iVar1 >> 1) {
      iVar2 = iVar2 + 1;
    }
    FUN_00534916(param_1,param_2,0,iVar2 * 2,param_3);
    FUN_005349a1(param_1,param_2,param_3);
  }
  return;
}

