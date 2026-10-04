
void FUN_0054176d(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  if ((int)(param_2 - param_1 & 0xfffffffcU) < 0x41) {
    iVar2 = param_1;
    if (param_1 != param_2) {
      while (iVar2 = iVar2 + 4, iVar2 != param_2) {
        FUN_00541cc7(param_1,iVar2,0,param_3);
      }
    }
  }
  else {
    iVar2 = param_1 + 0x40;
    iVar1 = param_1;
    if (param_1 != iVar2) {
      while (iVar1 = iVar1 + 4, iVar1 != iVar2) {
        FUN_00541cc7(param_1,iVar1,0,param_3);
      }
    }
    FUN_00541d80(iVar2,param_2,0,param_3);
  }
  return;
}

