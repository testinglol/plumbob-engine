
undefined4 __fastcall FUN_004c2284(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(param_1 + 0x24);
  *piVar1 = *piVar1 + -1;
  uVar2 = *(undefined4 *)(param_1 + 0x24);
  if (*piVar1 == 0) {
    if (param_1 != 0) {
      FUN_004c19cc();
      FUN_006321f0(param_1);
    }
    uVar2 = 0;
  }
  return uVar2;
}

