
void __fastcall FUN_004fea2d(int param_1)

{
  if (*(int *)(param_1 + 4) != *(int *)(param_1 + 8)) {
    FUN_004ff25e();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0xc;
    return;
  }
  FUN_004feb3d(*(int *)(param_1 + 4));
  return;
}

