
void __thiscall FUN_0050bdf3(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_0050be6e(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_0050c1ac();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x48;
  }
  return;
}

