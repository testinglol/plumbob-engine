
void FUN_004df5f4(int *param_1,int *param_2)

{
  SIZE_T SVar1;
  _SYSTEM_INFO local_44;
  _MEMORY_BASIC_INFORMATION local_20;
  
  GetSystemInfo(&local_44);
  if (local_44.lpMinimumApplicationAddress < local_44.lpMaximumApplicationAddress) {
    do {
      SVar1 = VirtualQuery(local_44.lpMinimumApplicationAddress,&local_20,0x1c);
      if (SVar1 == 0) {
        return;
      }
      if (((local_20.State != 0x10000) && (local_20.State != 0x2000)) &&
         (((byte)local_20.AllocationProtect & 1) == 0)) {
        if (((byte)local_20.AllocationProtect & 0xf0) == 0) {
          *param_1 = *param_1 + local_20.RegionSize;
        }
        else {
          *param_2 = *param_2 + local_20.RegionSize;
        }
      }
      local_44.lpMinimumApplicationAddress =
           (LPVOID)((int)local_44.lpMinimumApplicationAddress + local_20.RegionSize);
    } while (local_44.lpMinimumApplicationAddress < local_44.lpMaximumApplicationAddress);
  }
  return;
}

