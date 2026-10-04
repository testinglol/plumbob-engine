
void __thiscall FUN_004b1284(int param_1,int param_2)

{
  if (param_2 != 0) {
    FUN_00461765();
  }
  if (*(int *)(param_1 + 0x4bc) != 0) {
    FUN_0046176c();
    *(int *)(param_1 + 0x4bc) = 0;
  }
  *(int *)(param_1 + 0x4bc) = param_2;
  return;
}

