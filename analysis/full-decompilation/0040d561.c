
int __fastcall FUN_0040d561(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x80) == 0) {
    iVar2 = FUN_00408df0();
    *(int *)(param_1 + 0x80) = iVar2;
  }
  piVar1 = *(int **)(param_1 + 0x80);
  if (piVar1 != (int *)0x0) {
    return (piVar1[1] - *piVar1) / 0x98;
  }
  return 0;
}

