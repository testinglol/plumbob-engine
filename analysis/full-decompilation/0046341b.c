
int FUN_0046341b(byte param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = 1 << (param_1 & 0x1f);
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    if (0xf < iVar1) {
      if (iVar1 == 0x10) {
        *param_2 = 2;
        return 0x10;
      }
      if (iVar1 == 0x20) {
        *param_2 = 4;
        return 0x10;
      }
      if (iVar1 == 0x40) {
        *param_2 = 1;
        return 0x20;
      }
      if (iVar1 == 0x80) {
        *param_2 = 3;
        iVar1 = 0x20;
      }
    }
  }
  return iVar1;
}

