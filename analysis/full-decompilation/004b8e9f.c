
void __thiscall FUN_004b8e9f(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_004b8f14(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_004b90d0();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 8;
  }
  return;
}

