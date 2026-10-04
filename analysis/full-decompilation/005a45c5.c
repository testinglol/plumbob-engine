
uint __fastcall FUN_005a45c5(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = *(int *)(param_1 + 0x228);
  if (*(int *)(param_1 + 0x22c) < iVar2) {
    do {
      if (*(char *)(*(int *)(param_1 + 0x224) + *(int *)(param_1 + 0x22c)) == '{') break;
      iVar3 = *(int *)(param_1 + 0x22c) + 1;
      *(int *)(param_1 + 0x22c) = iVar3;
    } while (iVar3 < iVar2);
  }
  uVar4 = *(uint *)(param_1 + 0x22c);
  if ((int)uVar4 < iVar2) {
    iVar3 = uVar4 + 1;
    *(int *)(param_1 + 0x22c) = iVar3;
    if (iVar3 < iVar2) {
      do {
        cVar1 = *(char *)(iVar3 + *(int *)(param_1 + 0x224));
        if ((((cVar1 != ' ') && (cVar1 != '\t')) && (cVar1 != '\n')) && (cVar1 != '\r')) break;
        iVar3 = iVar3 + 1;
        *(int *)(param_1 + 0x22c) = iVar3;
      } while (iVar3 < iVar2);
    }
    uVar4 = *(uint *)(param_1 + 0x22c);
    if ((int)uVar4 < iVar2) {
      *(uint *)(param_1 + 0x230) = uVar4;
      do {
        if (*(char *)(*(int *)(param_1 + 0x224) + *(int *)(param_1 + 0x22c)) == '}') break;
        iVar3 = *(int *)(param_1 + 0x22c) + 1;
        *(int *)(param_1 + 0x22c) = iVar3;
      } while (iVar3 < iVar2);
      uVar4 = *(uint *)(param_1 + 0x22c);
      if ((int)uVar4 < iVar2) {
        *(uint *)(param_1 + 0x22c) = uVar4 + 1;
        *(uint *)(param_1 + 0x234) = uVar4 - *(int *)(param_1 + 0x230);
        return CONCAT31((int3)(uVar4 + 1 >> 8),1);
      }
    }
  }
  return uVar4 & 0xffffff00;
}

