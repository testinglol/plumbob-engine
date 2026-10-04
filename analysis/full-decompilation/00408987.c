
undefined4 * __thiscall FUN_00408987(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  FUN_0040f4b7(param_2);
  *param_1 = &PTR_FUN_00666634;
  puVar1 = param_1 + 4;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  puVar1 = param_1 + 0x10;
  iVar2 = 4;
  do {
    puVar1[-4] = 0;
    *puVar1 = 0;
    puVar1[4] = 0;
    puVar1[8] = 0;
    puVar1[0xc] = 0;
    puVar1[0x10] = 0;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return param_1;
}

