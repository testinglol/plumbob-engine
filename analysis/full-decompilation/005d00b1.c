
undefined4 __fastcall FUN_005d00b1(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x28);
  while( true ) {
    if (piVar3 == *(int **)(param_1 + 0x2c)) {
      return 0;
    }
    piVar1 = (int *)*piVar3;
    if (piVar1 == (int *)0x0) break;
    (**(code **)(*piVar1 + 8))();
    iVar2 = (**(code **)(*piVar1 + 4))();
    if (iVar2 == 1) {
      (**(code **)(*piVar1 + 4))();
      break;
    }
    piVar3 = piVar3 + 1;
  }
  FUN_005db2f2(piVar3);
  return 1;
}

