
int __thiscall FUN_0049da22(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar2 = *param_1;
  iVar4 = (param_1[1] - iVar2) / 0x28;
  uVar5 = iVar4 / 2;
  iVar1 = (param_3 - iVar2) / 0x28;
  while (iVar3 = iVar1, uVar5 != 0) {
    iVar1 = uVar5 + iVar3;
    if ((iVar4 <= iVar1) || (param_2 <= *(int *)(iVar2 + 4 + iVar1 * 0x28))) {
      uVar5 = uVar5 >> 1;
      iVar1 = iVar3;
    }
  }
  return iVar2 + iVar3 * 0x28;
}

