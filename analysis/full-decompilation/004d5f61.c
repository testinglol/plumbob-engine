
void __thiscall FUN_004d5f61(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_004d6076(*(int *)(param_1 + 4),param_2);
  }
  else {
    FUN_004d6224();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0xc;
  }
  return;
}

