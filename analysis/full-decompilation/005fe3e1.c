
undefined4 __thiscall FUN_005fe3e1(int *param_1,int param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x7c))(param_2);
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(*param_1 + 0x80))(param_2);
    if (cVar1 != '\0') {
      return 0x4e2;
    }
    if (param_2 == 0xc) {
      return 0x4e7;
    }
    if (param_2 == 0xd) {
      return 0x4e3;
    }
    if (param_2 == 0xf) {
      return 0x3a4;
    }
    if (param_2 == 0x11) {
      return 0x3b6;
    }
    if (param_2 == 0x12) {
      return 0x3a8;
    }
    if (param_2 == 0x13) {
      return 0x36a;
    }
    if (param_2 == 0x14) {
      return 0x3b5;
    }
  }
  return 0x4e4;
}

