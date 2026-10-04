
void __thiscall FUN_004129d9(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_00412b5c(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_00412eda();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x110;
  }
  return;
}

