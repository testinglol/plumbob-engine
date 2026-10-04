
undefined4 __fastcall FUN_005804ba(int param_1)

{
  char cVar1;
  int *piVar2;
  
  if (*(int **)(param_1 + 0xbc) != (int *)0x0) {
    piVar2 = (int *)(**(code **)(**(int **)(param_1 + 0xbc) + 0x98))();
    if (piVar2 != (int *)0x0) {
      cVar1 = (**(code **)(**(int **)(param_1 + 0xc0) + 0x24))();
      if (cVar1 != '\0') {
        (**(code **)(*piVar2 + 0x28))();
      }
    }
  }
  return 1;
}

