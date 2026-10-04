
undefined4 FUN_005bc302(uint *param_1,uint *param_2)

{
  uint uVar1;
  _MEMORYSTATUS local_24;
  
  local_24.dwLength = 0x20;
  GlobalMemoryStatus(&local_24);
  *param_1 = local_24.dwTotalPhys >> 0x14;
  *param_2 = local_24.dwAvailPhys >> 0x14;
  *param_1 = (*param_1 - 1 | 3) + 1;
  uVar1 = (*param_2 - 1 | 3) + 1;
  *param_2 = uVar1;
  return CONCAT31((int3)(uVar1 >> 8),1);
}

