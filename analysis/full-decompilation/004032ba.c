
undefined4 * __fastcall FUN_004032ba(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_0046f824(param_1 + 0x18,0,0x80);
  param_1[0x15] = &PTR_FUN_00666554;
  FUN_0046f824(param_1 + 0x3b,0,0x80);
  param_1[0x38] = &PTR_FUN_00666554;
  FUN_0046f824(param_1 + 0x5e,0,0x80);
  param_1[0x5b] = &PTR_FUN_00666554;
  FUN_0046f824(param_1 + 0x81,0,0x80);
  param_1[0x7e] = &PTR_FUN_00666554;
  FUN_0046f824(param_1 + 0xa4,0,0x40);
  param_1[0xa1] = &PTR_FUN_0066651c;
  FUN_0046f824(param_1 + 0xb7,0,0x40);
  param_1[0xb4] = &PTR_FUN_0066651c;
  FUN_0046f824(param_1 + 0xca,0,0x40);
  param_1[199] = &PTR_FUN_0066651c;
  FUN_0046f824(param_1 + 0xdd,0,0x40);
  param_1[0xda] = &PTR_FUN_0066651c;
  FUN_005b8680();
  puVar2 = param_1;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = param_1 + 10;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x14] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 9;
  param_1[0x13] = 0xf;
  return param_1;
}

