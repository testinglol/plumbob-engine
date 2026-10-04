
void FUN_005c0cb4(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  if ((int)(param_2 - param_1 & 0xfffffff0U) < 0x101) {
    iVar2 = param_1;
    if (param_1 != param_2) {
      while (iVar2 = iVar2 + 0x10, iVar2 != param_2) {
        FUN_005c0e69(param_1,iVar2,0,param_3);
      }
    }
  }
  else {
    iVar2 = param_1 + 0x100;
    iVar1 = param_1;
    if (param_1 != iVar2) {
      while (iVar1 = iVar1 + 0x10, iVar1 != iVar2) {
        FUN_005c0e69(param_1,iVar1,0,param_3);
      }
    }
    FUN_005c0d9f(iVar2,param_2,param_3);
  }
  return;
}

