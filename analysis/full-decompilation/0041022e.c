
undefined4 __fastcall FUN_0041022e(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_0045741b();
  piVar2 = *(int **)(param_1 + 300);
  while( true ) {
    if (piVar2 == *(int **)(param_1 + 0x130)) {
      return 0;
    }
    if (*piVar2 == iVar1) break;
    piVar2 = piVar2 + 1;
  }
  return 1;
}

