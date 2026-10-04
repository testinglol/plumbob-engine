
int __thiscall FUN_00418d1a(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_00418c28(param_2,0);
  if (piVar1 != *(int **)(param_1 + 4)) {
    if (param_4 != 0) {
      piVar1[4] = param_4;
    }
    for (iVar2 = *piVar1; iVar2 != piVar1[1]; iVar2 = iVar2 + 0x5c) {
      if ((*(int *)(iVar2 + 4) == param_3) &&
         ((char)((ushort)*(undefined2 *)(iVar2 + 8) >> 8) == '\0')) {
        return iVar2;
      }
    }
  }
  return 0;
}

