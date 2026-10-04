
void FUN_00584787(void)

{
  int iVar1;
  
  iVar1 = DAT_006f6b64;
  if (DAT_006f6b60 != '\0') {
    DAT_006f6b68 = 0;
    if (DAT_006f6b64 != 0) {
      FUN_0059e120();
      FUN_006321f0(iVar1);
    }
    iVar1 = DAT_006f6b6c;
    DAT_006f6b64 = 0;
    if (DAT_006f6b6c != 0) {
      FUN_005c2ee6();
      FUN_006321f0(iVar1);
    }
    iVar1 = DAT_006f6b70;
    DAT_006f6b6c = 0;
    if (DAT_006f6b70 != 0) {
      FUN_005c2ee6();
      FUN_006321f0(iVar1);
    }
    DAT_006f6b70 = 0;
    DAT_006f6b60 = '\0';
  }
  return;
}

