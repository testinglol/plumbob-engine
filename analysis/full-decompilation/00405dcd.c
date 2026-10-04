
undefined4 * __thiscall FUN_00405dcd(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = param_2;
  puVar3 = param_1;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = param_2 + 10;
  puVar3 = param_1 + 10;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  param_1[0x11] = param_2[0x11];
  param_1[0x12] = param_2[0x12];
  param_1[0x13] = param_2[0x13];
  param_1[0x14] = param_2[0x14];
  FUN_00405ead(param_2 + 0x15);
  FUN_00405ead(param_2 + 0x38);
  FUN_00405ead(param_2 + 0x5b);
  FUN_00405ead(param_2 + 0x7e);
  FUN_004030b4(param_2 + 0xa1);
  FUN_004030b4(param_2 + 0xb4);
  FUN_004030b4(param_2 + 199);
  FUN_004030b4(param_2 + 0xda);
  FUN_005b86bd(param_2 + 0xed);
  return param_1;
}

