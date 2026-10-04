
void __thiscall FUN_005eb73c(int param_1,int param_2,undefined1 param_3)

{
  if (-1 < param_2) {
    if (param_2 < (*(int *)(param_1 + 0x194) - *(int *)(param_1 + 400)) / 0x28) {
      *(undefined1 *)(*(int *)(param_1 + 400) + 0x10 + param_2 * 0x28) = param_3;
    }
  }
  return;
}

