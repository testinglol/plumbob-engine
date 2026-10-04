
undefined4 FUN_00582ecc(void)

{
  undefined4 uVar1;
  code *local_2c;
  code *local_28;
  code *local_24;
  undefined1 *local_20;
  undefined1 *local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined1 *local_10;
  code *local_c;
  code *local_8;
  
  uVar1 = 0;
  DAT_006f6a88 = FUN_00582f50(&DAT_006f6a90);
  if (DAT_006f6a88 != 0) {
    local_2c = FUN_00583594;
    local_24 = FUN_005835ac;
    local_28 = FUN_005835a0;
    local_20 = &LAB_005835b8;
    local_1c = &LAB_005835cc;
    local_18 = &LAB_005835e0;
    local_10 = &LAB_005835fc;
    local_14 = &LAB_005835f0;
    local_c = FUN_005a9320;
    local_8 = FUN_005a9340;
    if (DAT_006f6adc != (code *)0x0) {
      (*DAT_006f6adc)(&local_2c);
    }
    if (DAT_006f6a90 != (code *)0x0) {
      uVar1 = (*DAT_006f6a90)();
    }
  }
  return uVar1;
}

