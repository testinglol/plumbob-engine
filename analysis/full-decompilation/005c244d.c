
void __thiscall FUN_005c244d(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_005c277a(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_005c2c10();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 4;
  }
  return;
}

