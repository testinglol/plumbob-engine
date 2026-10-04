
int __thiscall FUN_0043c0bd(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 2 != 0) {
    piVar1 = *(int **)(param_1 + 0x20);
    do {
      if (*(int *)(*piVar1 + 0xc) == param_2) {
        return (*(int **)(param_1 + 0x20))[uVar2];
      }
      uVar2 = uVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (uVar2 < (uint)(*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 2));
  }
  return 0;
}

