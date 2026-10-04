
void __thiscall FUN_005cb537(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_005cb675(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_005cbd6b();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x2f0;
  }
  return;
}

