
void __thiscall FUN_005ebbb5(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_005ebc2c(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_005ebec4();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x28;
  }
  return;
}

