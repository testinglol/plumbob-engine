
void FUN_00562093(void)

{
  int *piVar1;
  
  piVar1 = &DAT_006f5b18;
  do {
    if (*piVar1 != 0) {
      FUN_006321f0(*piVar1);
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x6f5b60);
  piVar1 = &DAT_006f5b60;
  do {
    if (*piVar1 != 0) {
      FUN_006321f0(*piVar1);
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x6f5bb0);
  piVar1 = &DAT_006f5bb0;
  do {
    if (*piVar1 != 0) {
      FUN_006321f0(*piVar1);
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x6f5bc0);
  return;
}

