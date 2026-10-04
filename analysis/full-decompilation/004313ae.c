
bool __thiscall FUN_004313ae(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if ((param_3 != *(int *)(param_1 + 4)) || (param_2 != *(int *)(param_1 + 8))) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_006321f0(*(int *)(param_1 + 0xc));
    }
    *(int *)(param_1 + 4) = param_3;
    *(int *)(param_1 + 8) = param_2;
    if ((0 < param_2) && (0 < param_3)) {
      piVar3 = operator_new((*(int *)(param_1 + 0x1c) * param_3 + 4) * param_2);
      *(int **)(param_1 + 0xc) = piVar3;
      if (piVar3 != (int *)0x0) {
        *piVar3 = (int)(piVar3 + *(int *)(param_1 + 8));
        iVar4 = 1;
        if (1 < *(int *)(param_1 + 8)) {
          do {
            iVar2 = iVar4 * 4;
            iVar1 = iVar4 * 4;
            iVar4 = iVar4 + 1;
            *(int *)(*(int *)(param_1 + 0xc) + iVar1) =
                 *(int *)(param_1 + 0x1c) * *(int *)(param_1 + 4) +
                 *(int *)(*(int *)(param_1 + 0xc) + -4 + iVar2);
          } while (iVar4 < *(int *)(param_1 + 8));
        }
      }
      return *(int *)(param_1 + 0xc) != 0;
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return true;
}

