
undefined4 __thiscall FUN_00427368(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  if (param_3 != 0) {
    for (piVar1 = *(int **)(param_1 + 0x174); piVar1 != *(int **)(param_1 + 0x178);
        piVar1 = piVar1 + 2) {
      if (*piVar1 == param_3) {
        iVar2 = piVar1[1];
        goto LAB_00427391;
      }
    }
    iVar2 = 0;
LAB_00427391:
    if (iVar2 != 1) {
      return 0xffffffff;
    }
  }
  iVar2 = FUN_00425ddf(param_3);
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  *(int *)(param_2 + 0x110) = param_3;
  *(uint *)(param_2 + 0x138) = *(uint *)(param_2 + 0x138) & 0xfffffff7 | 4;
  return 0;
}

