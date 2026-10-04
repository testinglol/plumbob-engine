
void __fastcall FUN_004cfa7c(int param_1)

{
  if ((*(int *)(param_1 + 8) != 0) && (*(int *)(param_1 + 8) == 1)) {
    *(undefined4 *)(param_1 + 0xe8) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xe4) = 0;
    FUN_004cf4ff(3);
    FUN_0050a9b5();
  }
  return;
}

