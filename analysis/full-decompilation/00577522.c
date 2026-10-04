
undefined4 * __fastcall FUN_00577522(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  *param_1 = &PTR_LAB_006716d4;
  *(undefined1 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  FUN_005bc6b5(0xffffffff);
  param_1[10] = 0x400;
  param_1[0xb] = 0;
  param_1[0x11] = 1;
  param_1[0x12] = 1;
  param_1[0x14] = 1;
  param_1[0x17] = 1;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  *(undefined1 *)(param_1 + 0xf) = 0;
  *(undefined1 *)((int)param_1 + 0x3d) = 0;
  param_1[0x10] = 0;
  param_1[0x13] = 0;
  param_1[0x15] = 0xf;
  param_1[0x16] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 4;
  param_1[0x1d] = 3;
  param_1[0x1e] = 3;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  FUN_005d48d9();
  param_1[0x1028] = 100;
  param_1[0x102c] = 100;
  param_1[0x1029] = 0;
  *(undefined1 *)(param_1 + 0x102a) = 0;
  *(undefined1 *)((int)param_1 + 0x40a9) = 0;
  param_1[0x102b] = 0;
  param_1[0x102d] = 0;
  *param_1 = &PTR_LAB_00671618;
  puVar2 = param_1 + 0x25;
  for (iVar1 = 0x1000; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}

