
void __fastcall FUN_00410b1a(int param_1)

{
  short sVar1;
  char cVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  
  if ((((*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x24) != 0) && (*(int *)(param_1 + 0x10c) != 0))
      && ((int)*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x22) == *(int *)(param_1 + 0x10c))) &&
     (((cVar2 = FUN_004074bc(), cVar2 != '\0' && (*(int *)(param_1 + 0x128) != 0)) &&
      (iVar3 = FUN_00440914(0xb6c90029), iVar3 != 0)))) {
    psVar4 = (short *)(param_1 + 0x14e);
    iVar5 = 6;
    do {
      sVar1 = *(short *)(*(int *)(iVar3 + 0x2c) + (-0x14e - param_1) + (int)psVar4);
      if (*psVar4 < sVar1) {
        *psVar4 = sVar1;
      }
      psVar4 = psVar4 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return;
}

