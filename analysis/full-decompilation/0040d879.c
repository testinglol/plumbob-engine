
int __fastcall FUN_0040d879(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x84) == 0) {
    iVar2 = FUN_00408edd();
    *(int *)(param_1 + 0x84) = iVar2;
  }
  piVar1 = *(int **)(param_1 + 0x84);
  if (piVar1 != (int *)0x0) {
    return (piVar1[1] - *piVar1) / 0x98;
  }
  return 0;
}

