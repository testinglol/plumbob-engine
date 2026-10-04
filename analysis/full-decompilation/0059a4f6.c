
void __fastcall FUN_0059a4f6(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_1 + 0x5c) - *(int *)(param_1 + 0x58) >> 3;
  if (0 < iVar1) {
    iVar5 = *(int *)(param_1 + 0x4c);
    iVar3 = *(int *)(param_1 + 0x50);
    iVar2 = FUN_0059a1bc();
    iVar4 = *(int *)(param_1 + 0x58);
    iVar2 = iVar2 + (iVar3 - iVar5 >> 3) * 0x20;
    if (0 < iVar1) {
      do {
        iVar5 = iVar2;
        iVar3 = FUN_0059a1bc(iVar2);
        FUN_0059a567(iVar3 + *(int *)(iVar4 + 4) * 0x20,iVar5);
        iVar2 = iVar2 + 0x20;
        iVar4 = iVar4 + 8;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  return;
}

