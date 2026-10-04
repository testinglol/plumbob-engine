
void __fastcall FUN_004ecfac(int param_1)

{
  int *piVar1;
  
  *(undefined4 *)(param_1 + 0x11c) = 0;
  piVar1 = (int *)(param_1 + 0xd4);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    *(undefined4 *)(param_1 + 0xd4) = 0;
  }
  FUN_004ec9ed();
  FUN_005e46f0(1);
  return;
}

