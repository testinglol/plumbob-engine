
bool __thiscall FUN_005da398(int param_1,int param_2)

{
  int *piVar1;
  bool bVar2;
  int *piVar3;
  
  if (param_2 == 0) {
    bVar2 = false;
  }
  else if (param_2 == *(int *)(param_1 + 0x1c0)) {
    bVar2 = true;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x200));
    piVar1 = *(int **)(param_1 + 0x38);
    for (piVar3 = *(int **)(param_1 + 0x34); (piVar3 != piVar1 && (*piVar3 != param_2));
        piVar3 = piVar3 + 1) {
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x200));
    bVar2 = piVar3 != piVar1;
  }
  return bVar2;
}

