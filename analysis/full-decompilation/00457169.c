
undefined4 * __fastcall FUN_00457169(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  FUN_0046f824(param_1 + 8,0,0x40);
  param_1[5] = &PTR_FUN_0066651c;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x2a] = 0xffffffff;
  param_1[0x2b] = 0xffffffff;
  param_1[0x2c] = 0xffffffff;
  param_1[0x28] = 0;
  *(undefined2 *)(param_1 + 0x29) = 0;
  param_1[0x2e] = 0;
  param_1[0x2d] = 0xffff0000;
  puVar2 = param_1 + 0x1a;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}

