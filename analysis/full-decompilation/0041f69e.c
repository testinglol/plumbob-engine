
uint __thiscall FUN_0041f69e(int param_1,int param_2,short *param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)FUN_0041f748(*param_3 + 1);
  piVar2 = *(int **)(param_1 + 8);
  if (piVar1 != piVar2) {
    do {
      if ((*piVar1 == param_2) && ((param_4 == 0 || (piVar1[1] == param_4)))) break;
      piVar1 = piVar1 + 3;
    } while (piVar1 != piVar2);
    piVar2 = (int *)(((int)piVar1 - *(int *)(param_1 + 4)) / 0xc);
    *param_3 = (short)piVar2;
    if (piVar1 != *(int **)(param_1 + 8)) {
      return CONCAT22((short)((uint)piVar2 >> 0x10),(short)piVar1[2]);
    }
  }
  *param_3 = -1;
  return (uint)piVar2 & 0xffff0000;
}

