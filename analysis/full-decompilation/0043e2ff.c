
int __fastcall FUN_0043e2ff(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if ((DAT_006e4f0c == 0) &&
     (iVar3 = *(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 2, 0 < iVar3)) {
    do {
      iVar1 = FUN_0043ad1f(iVar2);
      if (*(short *)(*(int *)(iVar1 + 0x60) + 0x12) == 0xd) {
        iVar1 = FUN_0043ad1f(iVar2);
        DAT_006e4f0c = *(int *)(*(int *)(iVar1 + 0x60) + 0x1c);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar3);
  }
  return DAT_006e4f0c;
}

