
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e586d(int *param_1)

{
  if (DAT_006f25c0 != '\0') {
    (**(code **)(*param_1 + 0x24))(0x40);
    (**(code **)(*(int *)param_1[0x17] + 0x24))(0x40);
    DAT_006f25c0 = '\0';
    DAT_006f0080 = DAT_006f25c4;
    DAT_006f0084 = DAT_006f25c8;
    DAT_006f0bcc = DAT_006f25bc;
    DAT_006f0bbc = DAT_006f25b8;
    DAT_006f0bd0 = DAT_006f25b4;
    DAT_006f0bd4 = DAT_006f25b0;
    _DAT_006f0bc0 = DAT_006f25a8;
    _DAT_006f0bc4 = DAT_006f25ac;
  }
  return;
}

