
void FUN_005b67a0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint local_4;
  
  iVar3 = DAT_006fd748;
  local_4 = DAT_006d2284 << 5;
  iVar1 = FUN_0064a380(&local_4);
  DAT_006fd748 = iVar1;
  if (iVar1 != 0) {
    iVar2 = 0;
    DAT_006d2284 = local_4 >> 5;
    DAT_006fd748 = iVar3;
    if (DAT_006d2284 != 0) {
      do {
        DAT_006fd748 = iVar1;
        *(int *)(iVar1 + 0x18) = iVar3;
        iVar2 = iVar2 + 1;
        *(undefined4 *)(DAT_006fd748 + 0x1c) = 0x46524545;
        iVar1 = DAT_006fd748 + 0x20;
        iVar3 = DAT_006fd748;
      } while (iVar2 < (int)DAT_006d2284);
    }
  }
  return;
}

