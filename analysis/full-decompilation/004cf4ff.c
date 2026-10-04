
void __thiscall FUN_004cf4ff(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 0x9c) = param_2;
  if (param_2 != 0) {
    if ((param_2 == 1) || (param_2 == 2)) {
      FUN_004cf169(0,0);
      return;
    }
    if (param_2 != 3) {
      return;
    }
    if (*(int *)(param_1 + 0xe4) != 0) {
      uVar1 = FUN_004cba6a();
      FUN_004cf194(uVar1);
      return;
    }
  }
  FUN_004cf136(7,0xffffffff);
  return;
}

