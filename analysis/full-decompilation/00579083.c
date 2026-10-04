
undefined4 * __fastcall FUN_00579083(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  param_1[4] = 4;
  param_1[9] = 4;
  param_1[10] = 4;
  param_1[7] = 2;
  param_1[8] = 2;
  param_1[0xd] = 1;
  param_1[0xe] = 1;
  param_1[1] = 0x400;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[0xb] = 0x78;
  param_1[0xc] = 8;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  *param_1 = &PTR_FUN_00671734;
  puVar2 = param_1 + 0x11;
  for (iVar1 = 0x1000; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}

