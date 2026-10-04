
int __thiscall FUN_005b8e6a(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_3;
  if (*(int **)(param_1 + 0xc) == (int *)0x0) {
LAB_005b8ec0:
    param_3 = 0;
  }
  else {
    if (*(char *)(param_1 + 0x1c) == '\0') {
      (**(code **)(**(int **)(param_1 + 0xc) + 0x3c))(param_2,&param_3);
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x20) + 0x30));
      iVar1 = *(int *)(param_1 + 0x18);
      if (iVar1 <= *(int *)(param_1 + 0x10)) {
        iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x34))(*(int *)(param_1 + 0x14) + iVar1,0);
        if (iVar2 != *(int *)(param_1 + 0x14) + iVar1) {
          LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x20) + 0x30));
          goto LAB_005b8ec0;
        }
      }
      if (*(int *)(param_1 + 0x10) < iVar1 + iVar3) {
        iVar3 = *(int *)(param_1 + 0x10) - iVar1;
      }
      param_3 = iVar3;
      (**(code **)(**(int **)(param_1 + 0xc) + 0x3c))(param_2,&param_3);
      LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x20) + 0x30));
    }
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + param_3;
  }
  return param_3;
}

