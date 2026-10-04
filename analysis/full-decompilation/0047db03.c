
void FUN_0047db03(short param_1,int param_2)

{
  if (param_1 != 2) {
    if (param_1 == 0xd) {
      return;
    }
    if (param_1 == 0x18) {
      return;
    }
    if (param_1 == 0x1a) {
      return;
    }
    if (param_1 == 0x1b) {
      FUN_00473102(param_2);
      param_2 = param_2 + 4;
      goto LAB_0047db76;
    }
    if (param_1 == 0x2a) {
      FUN_004730c5(param_2);
      return;
    }
    if (param_1 != 0x2c) {
      FUN_00473102(param_2);
      FUN_00473102(param_2 + 2);
      FUN_00473102(param_2 + 4);
      FUN_00473102(param_2 + 6);
      return;
    }
  }
  FUN_00473102(param_2);
  param_2 = param_2 + 2;
LAB_0047db76:
  FUN_00473102(param_2);
  return;
}

