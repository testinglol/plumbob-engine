
undefined4 __fastcall FUN_0050aacf(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xfc) != 0) {
    iVar1 = FUN_00401f6f();
    if (iVar1 == 0) {
      return *(undefined4 *)(param_1 + 0xe8);
    }
    if (iVar1 == 1) {
      return *(undefined4 *)(param_1 + 0xe0);
    }
    if (iVar1 == 2) {
      return *(undefined4 *)(param_1 + 0xe4);
    }
    if (iVar1 == 3) {
      return *(undefined4 *)(param_1 + 0xec);
    }
    if (iVar1 == 4) {
      return *(undefined4 *)(param_1 + 0xf4);
    }
  }
  return 0;
}

