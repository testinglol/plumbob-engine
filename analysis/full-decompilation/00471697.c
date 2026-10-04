
void __fastcall FUN_00471697(int param_1)

{
  if (*(int *)(param_1 + 4) != *(int *)(param_1 + 8)) {
    FUN_00471fde();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 4;
    return;
  }
  FUN_004718e9(*(int *)(param_1 + 4));
  return;
}

