
undefined4 * __fastcall FUN_004ed1bd(undefined4 *param_1)

{
  DWORD DVar1;
  PHANDLE ProcessHeaps;
  int *piVar2;
  _MEMORY_BASIC_INFORMATION local_24;
  uint local_8;
  
  param_1[2] = 0;
  ProcessHeaps = (PHANDLE)(param_1 + 2);
  *param_1 = &PTR_LAB_006693f4;
  DVar1 = GetProcessHeaps(0x100,ProcessHeaps);
  local_8 = 0;
  param_1[1] = DVar1;
  if (DVar1 != 0) {
    piVar2 = param_1 + 0x103;
    do {
      VirtualQuery(*ProcessHeaps,&local_24,0x1c);
      local_8 = local_8 + 1;
      piVar2[-1] = (int)local_24.AllocationBase;
      *piVar2 = local_24.RegionSize + (int)local_24.AllocationBase;
      ProcessHeaps = ProcessHeaps + 1;
      piVar2 = piVar2 + 2;
    } while (local_8 < (uint)param_1[1]);
  }
  return param_1;
}

