
undefined4 __fastcall FUN_005491d4(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x194) != 0) {
    FUN_005450fd(*(undefined4 *)(param_1 + 0x198));
    (**(code **)(**(int **)(param_1 + 0x194) + 4))();
    return *(undefined4 *)(param_1 + 0x194);
  }
  uVar1 = FUN_005dd99d();
  return uVar1;
}

