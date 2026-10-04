
void __thiscall FUN_004716b8(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_00471b90(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_00471fea();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0xc;
  }
  return;
}

