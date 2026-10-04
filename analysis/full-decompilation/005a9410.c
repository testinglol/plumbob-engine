
void FUN_005a9410(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = 0;
    do {
      if (iVar2 != iVar1) {
        if (((&DAT_00703ea0)[iVar2] == (&DAT_00703ea0)[iVar1]) && ((&DAT_00703ea0)[iVar1] != 0)) {
          (&DAT_00703ea0)[iVar1] = 0;
        }
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x10);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  iVar2 = 0;
  do {
    if ((&DAT_00703ea0)[iVar2] != 0) {
      iVar1 = *(int *)((&DAT_00703ea0)[iVar2] + 0x40);
      FUN_005aa580(iVar2);
      if (iVar1 != 0) {
        FUN_00634ecc(iVar1);
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  DAT_006f779c = 0;
  return;
}

