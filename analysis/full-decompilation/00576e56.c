
int * __fastcall FUN_00576e56(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  piVar1 = (int *)*param_1;
  iVar2 = *piVar1;
  *param_1 = iVar2;
  if (iVar2 == 0) {
    iVar2 = param_1[1];
    uVar4 = (uint)piVar1[1] % (uint)(*(int *)(iVar2 + 8) - *(int *)(iVar2 + 4) >> 2);
    do {
      uVar4 = uVar4 + 1;
      if ((uint)(*(int *)(iVar2 + 8) - *(int *)(iVar2 + 4) >> 2) <= uVar4) {
        return param_1;
      }
      iVar3 = *(int *)(*(int *)(iVar2 + 4) + uVar4 * 4);
      *param_1 = iVar3;
    } while (iVar3 == 0);
  }
  return param_1;
}

