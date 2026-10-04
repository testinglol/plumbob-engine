
void __thiscall FUN_004e1564(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_004e15d8(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_004e1830();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x20;
  }
  return;
}

