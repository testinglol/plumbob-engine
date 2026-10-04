
int __thiscall FUN_005cfd0a(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x1c);
  while( true ) {
    if (piVar2 == *(int **)(param_1 + 0x20)) {
      return 0;
    }
    if (*piVar2 == param_2) break;
    piVar2 = piVar2 + 1;
  }
  if (piVar2 == *(int **)(param_1 + 0x20)) {
    return 0;
  }
  if ((*(int *)(*piVar2 + 0xd8) != 0) &&
     (iVar1 = (**(code **)(**(int **)(param_1 + 0x38) + 0x18))
                        (*(int **)(param_1 + 0x38),*(int *)(*piVar2 + 0xd8)), iVar1 != 0)) {
    return iVar1;
  }
  if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*piVar2)(1);
  }
  FUN_005db2f2(piVar2);
  return 0;
}

