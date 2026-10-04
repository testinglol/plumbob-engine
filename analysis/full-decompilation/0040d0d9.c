
int __fastcall FUN_0040d0d9(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x7c) == 0) {
    uVar2 = FUN_00408c57(0);
    *(undefined4 *)(param_1 + 0x7c) = uVar2;
  }
  piVar1 = *(int **)(param_1 + 0x7c);
  if (piVar1 != (int *)0x0) {
    return (piVar1[1] - *piVar1) / 0x98;
  }
  return 0;
}

