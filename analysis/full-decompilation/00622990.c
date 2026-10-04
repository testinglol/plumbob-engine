
undefined4 FUN_00622990(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  int iVar5;
  uint local_c;
  int local_8;
  
  pbVar1 = param_1 + 2;
  pbVar2 = param_1 + 1;
  bVar4 = *param_1;
  pbVar3 = param_1 + 3;
  param_1 = (byte *)0x0;
  local_c = 0;
  local_8 = 99999;
  iVar5 = ((uint)*pbVar3 - (uint)param_2[3]) * ((uint)*pbVar3 - (uint)param_2[3]) +
          ((uint)*pbVar1 - (uint)param_2[2]) * ((uint)*pbVar1 - (uint)param_2[2]) +
          ((uint)*pbVar2 - (uint)param_2[1]) * ((uint)*pbVar2 - (uint)param_2[1]) +
          ((uint)bVar4 - (uint)*param_2) * ((uint)bVar4 - (uint)*param_2);
  do {
    if (iVar5 < local_8) {
      param_1 = (byte *)(local_c & 0xff);
      local_8 = iVar5;
    }
    local_c = local_c + 1;
  } while ((int)local_c < 0x100);
  return CONCAT31((int3)(local_c >> 8),param_1._0_1_);
}

