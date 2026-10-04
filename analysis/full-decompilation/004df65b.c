
undefined4 FUN_004df65b(LPCSTR param_1)

{
  BOOL BVar1;
  SIZE_T SVar2;
  undefined4 uVar3;
  CHAR local_154 [260];
  _SYSTEM_INFO local_50;
  _MEMORY_BASIC_INFORMATION local_2c;
  LPCVOID local_10;
  HANDLE local_c;
  char local_5;
  
  BVar1 = CreateDirectoryA(param_1,(LPSECURITY_ATTRIBUTES)0x0);
  if (BVar1 == 0) {
LAB_004df777:
    uVar3 = 0;
  }
  else {
    GetSystemInfo(&local_50);
    local_5 = '\0';
    local_10 = local_50.lpMinimumApplicationAddress;
    if (local_50.lpMinimumApplicationAddress < local_50.lpMaximumApplicationAddress) {
      do {
        SVar2 = VirtualQuery(local_10,&local_2c,0x1c);
        if (SVar2 == 0) goto LAB_004df777;
        if (((local_2c.State != 0x10000) && (local_2c.State != 0x2000)) &&
           (((byte)local_2c.AllocationProtect & 1) == 0)) {
          if (((byte)local_2c.AllocationProtect & 0xf0) == 0) {
            if (((((byte)local_2c.AllocationProtect & 2) == 0) && (local_5 != '\0')) &&
               (((byte)local_2c.AllocationProtect & 4) != 0)) {
              wsprintfA(local_154,s____s_Blk_08x_txt_006c8c4c,param_1,local_2c.AllocationBase);
              local_c = CreateFileA(local_154,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,7,0x80,
                                    (HANDLE)0x0);
              if (local_c == (HANDLE)0xffffffff) {
                local_c = CreateFileA(local_154,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,4,0x80,
                                      (HANDLE)0x0);
              }
              if (local_c != (HANDLE)0x0) {
                FUN_004df77b(local_c,&local_2c);
                CloseHandle(local_c);
              }
            }
          }
          else {
            local_5 = '\x01';
          }
        }
        local_10 = (LPCVOID)((int)local_10 + local_2c.RegionSize);
      } while (local_10 < local_50.lpMaximumApplicationAddress);
    }
    uVar3 = 1;
  }
  return uVar3;
}

