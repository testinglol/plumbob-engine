
undefined1 __thiscall FUN_005da467(int param_1,int param_2)

{
  int *piVar1;
  undefined1 uVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x200));
  for (piVar1 = *(int **)(param_1 + 0x34);
      (piVar1 != *(int **)(param_1 + 0x38) && (*piVar1 != param_2)); piVar1 = piVar1 + 1) {
  }
  if (piVar1 == *(int **)(param_1 + 0x38)) {
    if (param_2 != *(int *)(param_1 + 0x1c0)) {
      uVar2 = 0;
      goto LAB_005da4b8;
    }
    *(undefined4 *)(param_1 + 0x1c0) = 0;
  }
  else {
    FUN_005db2f2(piVar1);
  }
  uVar2 = 1;
LAB_005da4b8:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x200));
  return uVar2;
}

