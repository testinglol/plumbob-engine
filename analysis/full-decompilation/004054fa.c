
void __thiscall FUN_004054fa(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_004056a3(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_00405f43();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0xc;
  }
  return;
}

