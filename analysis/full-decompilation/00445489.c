
void __thiscall FUN_00445489(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_00445724(param_1);
  if (iVar1 != param_2) {
    if (iVar1 != 0) {
      FUN_00432189((byte)*(undefined4 *)(iVar1 + 0x114) & 0x1d);
      FUN_004341a6(0);
      FUN_0044668c(iVar1);
    }
    if (param_2 == 0) {
      FUN_0040766a(0xe4,0);
    }
    else {
      FUN_00432189((byte)*(undefined4 *)(param_2 + 0x114) & 0x1f | 2);
      FUN_004341a6(0);
      FUN_0044668c(param_2);
      FUN_0040766a(0xe4,(int)*(short *)(param_2 + 0xf0));
    }
  }
  return;
}

