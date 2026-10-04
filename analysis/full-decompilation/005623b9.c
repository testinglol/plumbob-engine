
undefined4 __thiscall FUN_005623b9(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x164) == '\0') {
    if (param_2 == 0x1b) {
      if (*(int *)(param_1 + 0xd4) == 1) {
        FUN_00561954(0);
        FUN_005607f3(0);
      }
      else if (*(int *)(param_1 + 0xd4) == 2) {
        FUN_00561954(0);
      }
      uVar1 = 1;
    }
    else {
      uVar1 = FUN_005dd72f(param_2,param_3);
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

