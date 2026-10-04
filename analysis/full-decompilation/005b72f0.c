
void FUN_005b72f0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (DAT_006fd7d8 != 0) {
    FUN_005b6820(DAT_006fd7d8);
    iVar2 = 0;
    iVar1 = DAT_006fd7d0;
    if (0 < DAT_006fd7d4) {
      iVar3 = 0;
      do {
        if (*(int *)(iVar3 + 4 + iVar1) != 0) {
          FUN_005b7390(iVar2,*(undefined4 *)(iVar3 + iVar1));
          iVar1 = DAT_006fd7d0;
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0xc;
      } while (iVar2 < DAT_006fd7d4);
    }
    if (iVar1 != 0) {
      FUN_0064a3d0(iVar1);
      DAT_006fd7d0 = 0;
      DAT_006fd7d4 = 0;
    }
    FUN_005b6830(DAT_006fd7d8);
    iVar1 = DAT_006fd7d8;
    DAT_006fd7d8 = 0;
    FUN_005b6840(iVar1);
  }
  return;
}

