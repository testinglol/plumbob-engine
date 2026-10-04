
void FUN_005349a1(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  if ((param_2 - param_1) / 0x28 < 0x11) {
    iVar2 = param_1;
    if (param_1 != param_2) {
      while (iVar2 = iVar2 + 0x28, iVar2 != param_2) {
        FUN_00534d3b(param_1,iVar2,0,param_3);
      }
    }
  }
  else {
    iVar2 = param_1 + 0x280;
    iVar1 = param_1;
    if (param_1 != iVar2) {
      while (iVar1 = iVar1 + 0x28, iVar1 != iVar2) {
        FUN_00534d3b(param_1,iVar1,0,param_3);
      }
    }
    FUN_00534df3(iVar2,param_2,0,param_3);
  }
  return;
}

