
undefined4 __fastcall FUN_005c8e5f(uint param_1)

{
  undefined4 uVar1;
  undefined4 uStack_8;
  
  *(int *)(param_1 + 0x52c) = *(int *)(param_1 + 0x52c) + 1;
  if ((*(int *)(param_1 + 0xec) != 0) && (*(int *)(param_1 + 0x104) != 0)) {
    uStack_8 = param_1;
    FUN_005c9821();
    uStack_8 = uStack_8 & 0xffffff;
    if (*(char *)(param_1 + 0x44d) == '\0') {
      uVar1 = FUN_005c9346((int)&uStack_8 + 3);
    }
    else {
      uVar1 = FUN_005c8eb7((int)&uStack_8 + 3);
    }
    *(undefined4 *)(param_1 + 4) = uVar1;
    if (uStack_8._3_1_ == '\0') {
      FUN_005cac60();
    }
  }
  return *(undefined4 *)(param_1 + 4);
}

