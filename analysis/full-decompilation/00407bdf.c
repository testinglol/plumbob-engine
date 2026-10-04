
void __thiscall FUN_00407bdf(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_00407d70(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_0040872f();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x14;
  }
  return;
}

