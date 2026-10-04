
void __thiscall FUN_005db335(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_005db569(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_005db9ee();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x14;
  }
  return;
}

