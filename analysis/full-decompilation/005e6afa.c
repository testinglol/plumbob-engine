
void __thiscall FUN_005e6afa(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_005e6e76(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_005e71a3();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x2c;
  }
  return;
}

