
void FUN_0055c1b3(void)

{
  int *piVar1;
  
  piVar1 = &DAT_006f58f8;
  do {
    if (*piVar1 != 0) {
      FUN_006321f0(*piVar1);
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x6f5940);
  piVar1 = &DAT_006f5940;
  do {
    if (*piVar1 != 0) {
      FUN_006321f0(*piVar1);
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x6f5990);
  piVar1 = &DAT_006f5990;
  do {
    if (*piVar1 != 0) {
      FUN_006321f0(*piVar1);
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x6f59a0);
  return;
}

