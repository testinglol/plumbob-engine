
undefined4 * __thiscall
FUN_005fab0b(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_005f80bf(param_2,param_3);
  param_1[0x5d] = &PTR_LAB_006764dc;
  *(undefined1 *)(param_1 + 0x68) = 0;
  param_1[0x69] = 0;
  param_1[0x6a] = 0;
  *(undefined1 *)(param_1 + 0x6e) = param_4;
  param_1[0x66] = 0x41200000;
  param_1[0x67] = 0x459c4000;
  *param_1 = &PTR_FUN_006763e0;
  param_1[0x5d] = &PTR_LAB_006762e4;
  param_1[0xe] = 10;
  puVar2 = param_1 + 0x5e;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}

