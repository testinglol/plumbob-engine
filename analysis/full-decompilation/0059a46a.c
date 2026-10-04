
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0059a46a(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = (*(int *)(param_1 + 0x44) - *(int *)(param_1 + 0x40)) / 0x18;
  FUN_0059b033(local_c);
  uVar2 = _DAT_0066745c;
  *(undefined4 *)(param_1 + 0x84) = _DAT_0066745c;
  *(undefined4 *)(param_1 + 0x80) = uVar2;
  *(undefined4 *)(param_1 + 0x7c) = uVar2;
  uVar2 = _DAT_00667458;
  *(undefined4 *)(param_1 + 0x90) = _DAT_00667458;
  *(undefined4 *)(param_1 + 0x8c) = uVar2;
  *(undefined4 *)(param_1 + 0x88) = uVar2;
  if (0 < local_c) {
    local_8 = 0;
    do {
      iVar1 = *(int *)(local_8 + *(int *)(param_1 + 0x40) + 8);
      if (0 < iVar1) {
        FUN_005c74c0(iVar1,0x18);
        FUN_005c73b0();
      }
      local_8 = local_8 + 0x18;
      local_c = local_c + -1;
    } while (local_c != 0);
  }
  return;
}

