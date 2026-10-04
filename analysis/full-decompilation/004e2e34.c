
undefined4 * __fastcall FUN_004e2e34(undefined4 *param_1)

{
  FUN_0046f824(param_1 + 3,0,0x104);
  *param_1 = &PTR_FUN_006664e8;
  FUN_00429bf0();
  param_1[0x65] = 0;
  param_1[0x66] = 0;
  param_1[0x67] = 0;
  *(undefined1 *)(param_1 + 0x44) = 0;
  *(undefined1 *)(param_1 + 100) = *(undefined1 *)(DAT_006e486c + 100);
  return param_1;
}

