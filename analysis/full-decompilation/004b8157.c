
undefined4 FUN_004b8157(void)

{
  int iVar1;
  
  if (DAT_006f0664 == '\0') {
    iVar1 = FUN_00582ecc();
    if (iVar1 == 0) {
      return 0;
    }
    DAT_006f0664 = '\x01';
  }
  return 1;
}

