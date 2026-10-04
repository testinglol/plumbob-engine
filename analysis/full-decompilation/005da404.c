
undefined1 __thiscall FUN_005da404(int param_1,int param_2)

{
  int *piVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  if (*(char *)(param_1 + 0x1bc) == '\0') {
    *(int *)(param_1 + 0x1c0) = param_2;
    uVar2 = 1;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x200));
    for (piVar1 = *(int **)(param_1 + 0x34); piVar1 != *(int **)(param_1 + 0x38);
        piVar1 = piVar1 + 1) {
      if (*piVar1 == param_2) {
        if (piVar1 != *(int **)(param_1 + 0x38)) goto LAB_005da44a;
        break;
      }
    }
    FUN_005db2cb(&param_2);
    uVar2 = 1;
LAB_005da44a:
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x200));
  }
  return uVar2;
}

