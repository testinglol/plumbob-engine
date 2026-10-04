
int __thiscall FUN_00418dda(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)FUN_00418c28(param_2,0);
  if (piVar1 != *(int **)(param_1 + 4)) {
    if (param_4 != 0) {
      piVar1[4] = param_4;
    }
    for (iVar3 = *piVar1; iVar3 != piVar1[1]; iVar3 = iVar3 + 0x5c) {
      iVar2 = FUN_0046f973(param_3);
      if ((iVar2 == 0) && ((char)((ushort)*(undefined2 *)(iVar3 + 8) >> 8) == '\0')) {
        return iVar3;
      }
    }
  }
  return 0;
}

