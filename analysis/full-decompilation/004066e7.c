
undefined4 __thiscall FUN_004066e7(int param_1,short param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(param_1 + 0xc);
  while( true ) {
    if (*piVar2 == 0) {
      return 0;
    }
    if (iVar1 == param_2) break;
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 5;
    if (7 < iVar1) {
      return 0;
    }
  }
  return *(undefined4 *)(param_1 + 0xc + iVar1 * 0x14);
}

