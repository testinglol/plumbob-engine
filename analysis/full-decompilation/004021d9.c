
undefined4 FUN_004021d9(short param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    if (param_1 == 1) {
      uVar1 = 0x100;
    }
    else {
      if (param_1 == 2) {
        return 0x1000;
      }
      if (param_1 == 3) {
        return 0x2000;
      }
    }
  }
  return uVar1;
}

