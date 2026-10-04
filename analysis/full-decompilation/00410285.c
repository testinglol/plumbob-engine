
int __thiscall FUN_00410285(int param_1,int param_2)

{
  int *piVar1;
  uint3 uVar2;
  
  piVar1 = *(int **)(param_1 + 300);
  while( true ) {
    uVar2 = (uint3)((uint)piVar1 >> 8);
    if (piVar1 == *(int **)(param_1 + 0x130)) {
      return (uint)uVar2 << 8;
    }
    if (*piVar1 == param_2) break;
    piVar1 = piVar1 + 1;
  }
  return CONCAT31(uVar2,1);
}

