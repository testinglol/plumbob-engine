
void __thiscall FUN_00594d67(int param_1,undefined4 param_2)

{
  if ((*(int *)(param_1 + 0x1c) != 0) && (DAT_006f75e4 != (code *)0x0)) {
    (*DAT_006f75e4)(*(int *)(param_1 + 0x1c));
  }
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  return;
}

