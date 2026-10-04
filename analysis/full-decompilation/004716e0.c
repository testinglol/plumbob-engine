
void __fastcall FUN_004716e0(int param_1)

{
  if (*(int *)(param_1 + 4) != *(int *)(param_1 + 8)) {
    FUN_00472007();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0xc;
    return;
  }
  FUN_00471a0e(*(int *)(param_1 + 4));
  return;
}

