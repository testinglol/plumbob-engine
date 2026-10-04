
void __thiscall FUN_004133c0(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_0041342c(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_004139e7();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x15c;
  }
  return;
}

