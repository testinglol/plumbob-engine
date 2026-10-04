
undefined4 __thiscall FUN_004742a0(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    param_1 = param_1 + 0x78;
  }
  else {
    if (param_2 != 1) {
      return 0;
    }
    param_1 = param_1 + 0xc;
  }
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = FUN_0046fbe5(0xffffffff);
  return uVar1;
}

