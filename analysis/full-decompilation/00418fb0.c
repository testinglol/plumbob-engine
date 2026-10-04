
short __thiscall FUN_00418fb0(int param_1,undefined4 param_2,short param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_00418c28(param_2,0);
  if (piVar1 != *(int **)(param_1 + 4)) {
    for (iVar2 = *piVar1; iVar2 != piVar1[1]; iVar2 = iVar2 + 0x5c) {
      if ((int)param_3 < *(int *)(iVar2 + 4)) {
        param_3 = *(short *)(iVar2 + 4);
      }
    }
  }
  return param_3;
}

