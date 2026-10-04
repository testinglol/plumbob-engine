
void __thiscall FUN_00473209(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 4 + *(int *)(param_1 + 0xfa8) * 4) = *param_2;
  *(int *)(param_1 + 0xfa8) = *(int *)(param_1 + 0xfa8) + 1;
  if (*(int *)(param_1 + 0xfa8) == *(int *)(param_1 + 0xfa4)) {
    *(undefined4 *)(param_1 + 0xfa8) = 0;
  }
  if (*(int *)(param_1 + 0xfb0) == 0) {
    if (*(int *)(param_1 + 0xfa8) == *(int *)(param_1 + 0xfac)) {
      *(undefined4 *)(param_1 + 0xfb0) = 1;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0xfac) = *(undefined4 *)(param_1 + 0xfa8);
  }
  return;
}

