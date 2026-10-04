
undefined4 __fastcall FUN_0053d900(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(param_1 + 0x20);
  *piVar1 = *piVar1 + -1;
  uVar2 = *(undefined4 *)(param_1 + 0x20);
  if (*piVar1 == 0) {
    if (param_1 != 0) {
      FUN_0053c249();
      FUN_006321f0(param_1);
    }
    uVar2 = 0;
  }
  return uVar2;
}

