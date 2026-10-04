
undefined4 * __fastcall FUN_0054231a(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  param_1[0xe9] = 0;
  param_1[0xea] = 0;
  param_1[0xeb] = 0;
  *param_1 = &PTR_FUN_0066f3e0;
  puVar2 = param_1 + 9;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = param_1 + 0x19;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  param_1[0x20] = 0;
  param_1[0xe1] = 0xffffffff;
  *(undefined1 *)(param_1 + 0xe2) = 0;
  param_1[0xe4] = 0;
  param_1[0x1f] = 0;
  param_1[0x23] = 0;
  param_1[0xe5] = 0;
  param_1[0xe6] = 0;
  param_1[0xe3] = 0;
  param_1[0xe7] = 0;
  param_1[0xe8] = 0;
  return param_1;
}

