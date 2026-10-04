
void FUN_006240a0(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  iVar2 = *(int *)(iVar1 + 0x24);
  iVar3 = iVar1 + 0x28;
  if (0 < iVar2) {
    iVar1 = (*param_2 - iVar1) + iVar3;
    do {
      FUN_00623dd0(iVar3,iVar1);
      iVar3 = iVar3 + 4;
      iVar1 = iVar1 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

