
void FUN_0041e921(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((int)(param_2 - param_1 & 0xfffffff8U) < 0x81) {
    iVar2 = param_1;
    if (param_1 != param_2) {
      while (iVar2 = iVar2 + 8, iVar2 != param_2) {
        FUN_0041eafa(param_1,iVar2,0);
      }
    }
  }
  else {
    iVar2 = param_1 + 0x80;
    iVar1 = param_1;
    if (param_1 != iVar2) {
      while (iVar1 = iVar1 + 8, iVar1 != iVar2) {
        FUN_0041eafa(param_1,iVar1,0);
      }
    }
    FUN_0041eb55(iVar2,param_2,0);
  }
  return;
}

