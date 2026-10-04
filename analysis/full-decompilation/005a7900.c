
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a7900(int param_1,int param_2,int param_3)

{
  float fVar1;
  
  do {
    DAT_006f76d8 = (float *)(*DAT_006f76d0 * DAT_006d200c + param_2);
    DAT_006f76c8 = (float *)(*DAT_006f76d0 * DAT_006d2010 + param_3);
    DAT_006f76d4 = (float *)(DAT_006f7704 + *DAT_006f76d0 * 0xc);
    fVar1 = _DAT_006722b4;
    if (DAT_006f76d8[2] != 0.0) {
      fVar1 = _DAT_00672294 / DAT_006f76d8[2];
    }
    DAT_006f76d0 = DAT_006f76d0 + 1;
    *DAT_006f76d4 = *DAT_006f76d8;
    *DAT_006f76c8 = *DAT_006f76d4 * DAT_006d20f4 * fVar1 + DAT_006d20fc;
    DAT_006f76d4 = DAT_006f76d4 + 1;
    *DAT_006f76d4 = DAT_006f76d8[1];
    DAT_006f76c8[1] = DAT_006d2100 - *DAT_006f76d4 * DAT_006d20f8 * fVar1;
    DAT_006f76d4 = DAT_006f76d4 + 1;
    *DAT_006f76d4 = DAT_006f76d8[2];
    DAT_006f76c8[2] = (*DAT_006f76d4 - DAT_006d20e0) * DAT_006d20f0;
    DAT_006f76d4 = DAT_006f76d4 + 1;
    param_1 = param_1 + -1;
    DAT_006f76c8[3] = fVar1;
  } while (param_1 != 0);
  return;
}

