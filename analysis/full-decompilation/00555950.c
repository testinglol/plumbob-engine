
void __thiscall FUN_00555950(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x118);
  if ((((iVar1 == 2) || (iVar1 == 4)) || (iVar1 == 8)) ||
     (((iVar1 == 0x20 || (iVar1 == 0x40)) || ((iVar1 == 0x800 || (iVar1 == 0x1000)))))) {
    FUN_005e46f0(0);
  }
  if (param_2 == 0) {
    FUN_005554a4(0x1000);
  }
  else if (param_2 == 1) {
    FUN_005554a4(0x20);
  }
  else if (param_2 == 2) {
    FUN_005554a4(8);
  }
  else if (param_2 == 3) {
    FUN_005554a4(4);
  }
  else if (param_2 == 4) {
    FUN_005554a4(2);
  }
  else if (param_2 == 5) {
    FUN_005554a4(0x40);
  }
  else {
    if (param_2 != 6) {
      return;
    }
    FUN_005554a4(0x800);
  }
  FUN_005e46f0(1);
  return;
}

