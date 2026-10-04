
void __thiscall FUN_005043cc(int param_1,char param_2)

{
  undefined4 uVar1;
  
  if (param_2 == '\0') {
    if (*(int *)(param_1 + 0xec) == 0) {
      return;
    }
    uVar1 = 0;
  }
  else {
    if (*(int *)(param_1 + 0xec) == 0) {
      return;
    }
    uVar1 = 1;
  }
  FUN_005e46f0(uVar1);
  return;
}

