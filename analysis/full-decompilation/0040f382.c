
int __fastcall FUN_0040f382(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x94) == 0) {
    iVar2 = FUN_0040f001();
    *(int *)(param_1 + 0x94) = iVar2;
  }
  piVar1 = *(int **)(param_1 + 0x94);
  if (piVar1 != (int *)0x0) {
    return (piVar1[1] - *piVar1) / 0x98;
  }
  return 0;
}

