
void __thiscall FUN_005c125b(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_005c1283(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_005c144d();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x20;
  }
  return;
}

