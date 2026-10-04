
void __thiscall FUN_004e3bd4(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_004e3c48(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_004e3e47();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x10;
  }
  return;
}

