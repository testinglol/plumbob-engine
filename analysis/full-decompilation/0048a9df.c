
void __thiscall FUN_0048a9df(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x2c) == 0) {
    return;
  }
  *(undefined2 *)(*(int *)(param_1 + 0x2c) + 0x4a) = 2;
  if (param_2 == 0) {
LAB_0048aa02:
    uVar1 = 0;
  }
  else {
    if (param_2 != 1) {
      if (param_2 == 2) goto LAB_0048aa02;
      if (param_2 != 3) {
        return;
      }
    }
    uVar1 = 6;
  }
  FUN_004d25a5(uVar1);
  return;
}

