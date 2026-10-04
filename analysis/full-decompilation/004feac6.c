
void __thiscall FUN_004feac6(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_004fef01(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_004ff288();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0xc;
  }
  return;
}

