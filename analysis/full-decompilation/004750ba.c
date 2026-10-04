
undefined4 __fastcall FUN_004750ba(int param_1)

{
  ushort *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = (*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10) >> 2) + -1;
  if (-1 < iVar4) {
    do {
      puVar1 = (ushort *)FUN_004754ac((int)(short)iVar3);
      if ((*puVar1 == 0xffff) || ((*puVar1 & 0x7fff) == 0xffff)) {
        iVar4 = iVar3 + -1;
        break;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= iVar4);
  }
  if (iVar4 == -1) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004754ac((int)(short)iVar4);
  }
  return uVar2;
}

