
int FUN_004e9957(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_004e9902();
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      iVar2 = FUN_004e9918(iVar3);
      if (iVar2 == param_1) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return -1;
}

