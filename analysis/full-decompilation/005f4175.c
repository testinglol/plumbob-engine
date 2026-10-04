
int __thiscall FUN_005f4175(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int local_8;
  
  local_8 = 0;
  if (0 < (int)(*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) & 0xfffffffcU)) {
    piVar4 = *(int **)(param_1 + 0xf0);
    do {
      piVar1 = (int *)*piVar4;
      iVar2 = *piVar1;
      if ((param_2 < iVar2) || (iVar3 = param_2, piVar1[1] + iVar2 <= param_2)) {
        if (param_2 == piVar1[1] + iVar2) goto LAB_005f41ca;
        if (iVar2 <= param_2) {
          iVar3 = -3;
          goto LAB_005f41c1;
        }
      }
      else {
LAB_005f41c1:
        if (-1 < iVar3) {
          return local_8;
        }
        if (iVar3 == -1) {
LAB_005f41ca:
          if (local_8 == (*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2) + -1) {
            return local_8;
          }
        }
      }
      local_8 = local_8 + 1;
      piVar4 = piVar4 + 1;
    } while (local_8 < *(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2);
  }
  return (*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2) + -1;
}

