
uint __thiscall FUN_0056f209(byte *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (uint)(*param_1 >> 4);
  if ((*param_1 & 2) == 0) {
    if (param_2 != 0) {
      uVar1 = (uint)(byte)(&DAT_006f62e4)[uVar1 + param_2 * 0x10];
    }
  }
  else if (param_2 != 0) {
    uVar1 = (uint)(byte)(&DAT_006f62b4)[uVar1 + param_2 * 0x10];
  }
  return uVar1;
}

