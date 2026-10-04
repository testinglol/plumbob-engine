
undefined4 * __thiscall FUN_0050044b(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_005dbd68();
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  param_1[0x37] = param_3;
  param_1[0x35] = param_2;
  *param_1 = &PTR_FUN_00669e30;
  *(undefined1 *)(param_1 + 0x38) = 1;
  param_1[0x36] = 0;
  puVar2 = param_1 + 0x3d;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x55] = 0;
  param_1[0x57] = 0;
  *(undefined1 *)(param_1 + 0x5c) = 1;
  param_1[0x5d] = 0;
  *(undefined1 *)(param_1 + 0x5e) = 0;
  param_1[0x5f] = 0;
  param_1[0x60] = 0;
  return param_1;
}

