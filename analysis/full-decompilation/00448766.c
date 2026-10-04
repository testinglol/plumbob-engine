
void __thiscall FUN_00448766(int param_1,undefined4 *param_2)

{
  if (*(int *)(param_1 + 4) == *(int *)(param_1 + 8)) {
    FUN_00449916(*(undefined4 *)(param_1 + 4),param_2);
  }
  else {
    if (*(undefined4 **)(param_1 + 4) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 4) = *param_2;
    }
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 4;
  }
  return;
}

