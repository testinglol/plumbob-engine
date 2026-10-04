
undefined4 __thiscall FUN_005b8f4a(int param_1,int param_2)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x1c) == '\0') {
    if (*(int **)(param_1 + 0xc) == (int *)0x0) {
      return 0;
    }
    if (*(int *)(param_1 + 0x10) < param_2) {
      return 0;
    }
    if ((*(int *)(param_1 + 0x18) != param_2) &&
       (iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x34))
                          (*(int *)(param_1 + 0x14) + param_2,0),
       iVar1 != *(int *)(param_1 + 0x14) + param_2)) {
      return 0;
    }
    *(int *)(param_1 + 0x18) = param_2;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x20) + 0x30));
    if (((*(int **)(param_1 + 0xc) == (int *)0x0) || (*(int *)(param_1 + 0x10) < param_2)) ||
       ((*(int *)(param_1 + 0x18) != param_2 &&
        (iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x34))
                           (*(int *)(param_1 + 0x14) + param_2,0),
        iVar1 != *(int *)(param_1 + 0x14) + param_2)))) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x20) + 0x30));
      return 0;
    }
    *(int *)(param_1 + 0x18) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x20) + 0x30));
  }
  return 1;
}

