
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00420f9d(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (DAT_006e49ec == 0) {
    (**(code **)(DAT_006e48f0 + 8))();
  }
  uVar1 = _DAT_00666a5c;
  puVar3 = param_1;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  puVar3 = param_1 + 0x10;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  param_1[0x15] = uVar1;
  param_1[5] = uVar1;
  param_1[0xb] = 0;
  param_1[0x20] = 0;
  param_1[7] = 0xc2200000;
  return;
}

