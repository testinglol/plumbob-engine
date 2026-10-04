
void FUN_004e51b0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((int)(param_2 - param_1 & 0xfffffffcU) < 0x41) {
    iVar2 = param_1;
    if (param_1 != param_2) {
      while (iVar2 = iVar2 + 4, iVar2 != param_2) {
        FUN_004e52e0(param_1,iVar2,0);
      }
    }
  }
  else {
    iVar2 = param_1 + 0x40;
    iVar1 = param_1;
    if (param_1 != iVar2) {
      while (iVar1 = iVar1 + 4, iVar1 != iVar2) {
        FUN_004e52e0(param_1,iVar1,0);
      }
    }
    FUN_004e523f(iVar2,param_2);
  }
  return;
}

