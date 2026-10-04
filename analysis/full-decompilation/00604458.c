
void __thiscall FUN_00604458(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_006044f9(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_0060475f();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x1c;
  }
  return;
}

