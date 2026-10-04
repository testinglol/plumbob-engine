
void __thiscall FUN_004905d0(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 0x2c) = param_2;
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    if (param_2 != 1) {
      return;
    }
    uVar1 = 6;
  }
  FUN_004d25a5(uVar1);
  return;
}

