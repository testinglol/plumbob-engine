
int __thiscall FUN_0041f12e(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x10);
  if (piVar1 != (int *)0x0) {
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 4)) {
      do {
        if (*(int *)(*piVar1 + 0x18) == param_2) {
          return *piVar1;
        }
        iVar2 = iVar2 + 1;
        piVar1 = piVar1 + 1;
      } while (iVar2 < *(int *)(param_1 + 4));
    }
  }
  return 0;
}

