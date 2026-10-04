
int __fastcall FUN_0040dea9(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x8c) == 0) {
    iVar2 = FUN_004090b7();
    *(int *)(param_1 + 0x8c) = iVar2;
  }
  piVar1 = *(int **)(param_1 + 0x8c);
  if (piVar1 != (int *)0x0) {
    return (piVar1[1] - *piVar1) / 0x98;
  }
  return 0;
}

