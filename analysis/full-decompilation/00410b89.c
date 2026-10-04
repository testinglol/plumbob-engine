
void __fastcall FUN_00410b89(int param_1)

{
  char cVar1;
  int iVar2;
  short *psVar3;
  short *psVar4;
  int iVar5;
  
  if ((((*(char *)(param_1 + 0x14c) != '\0') && (*(int *)(param_1 + 0x10c) != 0)) &&
      ((int)*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x22) == *(int *)(param_1 + 0x10c))) &&
     (((cVar1 = FUN_004074bc(), cVar1 != '\0' && (*(int *)(param_1 + 0x128) != 0)) &&
      (iVar2 = FUN_00440914(0xb6c90029), iVar2 != 0)))) {
    iVar5 = 0;
    psVar4 = (short *)(param_1 + 0x14e);
    do {
      psVar3 = (short *)(*(int *)(iVar2 + 0x2c) + iVar5);
      if (*psVar3 < *psVar4) {
        *psVar3 = *psVar4;
      }
      iVar5 = iVar5 + 2;
      psVar4 = psVar4 + 1;
    } while (iVar5 < 0xc);
  }
  return;
}

