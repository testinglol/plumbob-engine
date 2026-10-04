
void FUN_005a7020(int param_1,int param_2,int param_3)

{
  do {
    DAT_006f76d8 = (float *)(*DAT_006f76d0 * DAT_006d200c + param_2);
    DAT_006f76c8 = (float *)(*DAT_006f76d0 * DAT_006d2010 + param_3);
    param_1 = param_1 + -1;
    DAT_006f76d0 = DAT_006f76d0 + 1;
    *DAT_006f76c8 = *DAT_006f76e4 + *DAT_006f76d8;
    DAT_006f76c8[1] = DAT_006f76e4[1] + DAT_006f76d8[1];
    DAT_006f76c8[2] = DAT_006f76e4[2] + DAT_006f76d8[2];
  } while (param_1 != 0);
  return;
}

