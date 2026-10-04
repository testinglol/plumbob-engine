
undefined4 FUN_005ca4e5(undefined1 *param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = (uint)CONCAT21(CONCAT11(*param_1,param_1[1]),param_1[2]);
  if (param_2 == 1) {
    uVar1 = FUN_0049f1f4(uVar2);
    return uVar1;
  }
  if (param_2 == 2) {
    uVar1 = FUN_0049f21b(uVar2);
    return uVar1;
  }
  if (param_2 == 3) {
    uVar1 = FUN_004a4558(uVar2);
    return uVar1;
  }
  if (param_2 + -4 != 0) {
    return CONCAT22((short)((uint)(param_2 + -4) >> 0x10),0xffff);
  }
  uVar1 = FUN_004a4531(uVar2);
  return uVar1;
}

