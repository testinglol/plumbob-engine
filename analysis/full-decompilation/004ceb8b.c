
bool __fastcall FUN_004ceb8b(int param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  
  if (*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x24) == 99) {
    iVar1 = *(int *)(param_1 + 0x34);
    bVar4 = SBORROW4(iVar1,2);
    iVar2 = iVar1 + -2;
    bVar3 = iVar1 == 2;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x34);
    bVar4 = SBORROW4(iVar1,1);
    iVar2 = iVar1 + -1;
    bVar3 = iVar1 == 1;
  }
  return !bVar3 && bVar4 == iVar2 < 0;
}

