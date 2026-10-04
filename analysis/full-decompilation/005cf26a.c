
void __thiscall FUN_005cf26a(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_005cf3c9(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_005cf5af();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x44;
  }
  return;
}

