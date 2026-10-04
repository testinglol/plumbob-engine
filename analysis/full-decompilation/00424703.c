
void __thiscall FUN_00424703(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = *(int **)(param_1 + 0x154);
  piVar1 = *(int **)(param_1 + 0x158);
  *(undefined1 *)(param_2 + 0x24) = 1;
  if (piVar2 != piVar1) {
    do {
      if (*(int *)(*piVar2 + 0x10c) == (int)*(short *)(param_2 + 0xee)) {
        iVar3 = *piVar2;
        goto LAB_00424736;
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 != piVar1);
  }
  iVar3 = 0;
LAB_00424736:
  if (iVar3 != 0) {
    *(undefined1 *)(iVar3 + 0x124) = 1;
  }
  return;
}

