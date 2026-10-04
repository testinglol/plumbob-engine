
void FUN_0056865f(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 < 0x41) {
    if (param_1 == 0x40) {
      uVar1 = 4;
    }
    else if (param_1 == 2) {
      uVar1 = 3;
    }
    else if (param_1 == 4) {
      uVar1 = 2;
    }
    else if (param_1 == 8) {
      uVar1 = 1;
    }
  }
  else if (param_1 == 0x80) {
    uVar1 = 5;
  }
  else if (param_1 == 0x100) {
    uVar1 = 6;
  }
  else if (param_1 == 0x200) {
    uVar1 = 7;
  }
  else if (param_1 == 0x400) {
    uVar1 = 8;
  }
  FUN_0056778c(uVar1);
  return;
}

