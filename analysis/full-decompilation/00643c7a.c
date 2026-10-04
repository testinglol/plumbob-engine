
undefined4 FUN_00643c7a(short param_1)

{
  short *psVar1;
  
  psVar1 = &DAT_006dd9c4;
  do {
    if (param_1 == *psVar1) {
      return 0;
    }
    psVar1 = psVar1 + 1;
  } while ((int)psVar1 < 0x6dd9d8);
  return 1;
}

