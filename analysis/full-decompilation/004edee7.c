
undefined4 __fastcall FUN_004edee7(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = 0;
  uVar4 = 0;
  if (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2 != 0) {
    do {
      cVar1 = FUN_004ed555();
      if (cVar1 != '\0') {
        iVar3 = iVar3 + 1;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2));
  }
  iVar2 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);
  return CONCAT31((int3)(iVar2 >> 10),iVar3 == iVar2 >> 2);
}

