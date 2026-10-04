
int FUN_0042debc(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = *(int *)(DAT_006e486c + 0x24);
  if (iVar1 != 0) {
    for (piVar4 = *(int **)(iVar1 + 0x154); piVar4 != *(int **)(iVar1 + 0x158); piVar4 = piVar4 + 1)
    {
      iVar2 = *piVar4;
      if ((iVar2 != 0) && (iVar3 = FUN_00410263(param_1), iVar3 != 0)) {
        return iVar2;
      }
    }
  }
  return 0;
}

