
void FUN_005c0b17(uint *param_1,uint param_2)

{
  int iVar1;
  ulonglong uVar2;
  BOOL BVar3;
  short sVar4;
  uint uVar5;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  LARGE_INTEGER local_20;
  LARGE_INTEGER local_18;
  LARGE_INTEGER local_10;
  int local_8;
  
  uVar5 = 0xffffffff;
  _memset(&local_30,0,0x10);
  BVar3 = QueryPerformanceFrequency(&local_20);
  if (BVar3 != 0) {
    local_8 = 10;
    do {
      QueryPerformanceCounter(&local_18);
      sVar4 = 4000;
      do {
        for (iVar1 = 0; (0x80000000U >> iVar1 & 1) == 0; iVar1 = iVar1 + 1) {
        }
        sVar4 = sVar4 + -1;
      } while (sVar4 != 0);
      QueryPerformanceCounter(&local_10);
      if (local_10.s.LowPart - local_18._0_4_ < uVar5) {
        uVar5 = local_10.s.LowPart - local_18._0_4_;
      }
      local_8 = local_8 + -1;
    } while (local_8 != 0);
    uVar2 = (ulonglong)(uVar5 * 100000) / ((ulonglong)local_20.s.LowPart / 10);
    local_2c = (uint)uVar2;
    if (local_20.s.LowPart >> 1 < (uint)(uVar2 % (ulonglong)local_20.s.LowPart)) {
      local_2c = local_2c + 1;
    }
    local_28 = param_2 / local_2c;
    local_24 = local_28;
    if (local_2c >> 1 < param_2 % local_2c) {
      local_24 = local_28 + 1;
    }
    local_30 = param_2;
  }
  *param_1 = local_30;
  param_1[1] = local_2c;
  param_1[2] = local_28;
  param_1[3] = local_24;
  return;
}

