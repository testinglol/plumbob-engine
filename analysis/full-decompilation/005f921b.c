
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __fastcall FUN_005f921b(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_8;
  
  _memset(&local_18,0,0x14);
  local_18 = 0x14;
  puVar1 = (undefined4 *)(param_1 + 0x80);
  local_10 = 0;
  local_8 = 0;
  local_14 = 0x11;
  iVar2 = (**(code **)(*DAT_006fed6c + 0xc))(DAT_006fed6c,&local_18,puVar1,0);
  if (iVar2 != 0) {
    local_14 = 1;
    uVar3 = (**(code **)(*DAT_006fed6c + 0xc))(DAT_006fed6c,&local_18,puVar1,0);
    if (uVar3 != 0) {
      return uVar3 & 0xffffff00;
    }
  }
  _DAT_006fed44 = _DAT_006fed44 + 1;
  iVar2 = (**(code **)(*(int *)*puVar1 + 0x38))((int *)*puVar1,param_1 + 0xa8);
  return CONCAT31((int3)((uint)-iVar2 >> 8),'\x01' - (iVar2 != 0));
}

