
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a6810(void)

{
  if (_DAT_006d21bc != 0) {
    MXCSR = 0x9f80;
    if (DAT_006d21d0 != 0) {
      MXCSR = 0x9fc0;
    }
  }
  return;
}

