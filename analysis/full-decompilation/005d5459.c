
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_005d5459(void)

{
  undefined8 uVar1;
  uint uVar2;
  int iVar3;
  float10 fVar4;
  LARGE_INTEGER local_2c;
  LARGE_INTEGER local_24;
  LARGE_INTEGER local_1c;
  undefined4 local_14;
  int local_10;
  
  uVar2 = FUN_005bdf5b();
  if ((uVar2 & 0x10) != 0) {
    DAT_006fe8b0 = '\x01';
  }
  if (DAT_006fe8b0 == '\0') {
    fVar4 = (float10)_DAT_00667280;
  }
  else {
    QueryPerformanceFrequency(&local_2c);
    QueryPerformanceCounter(&local_24);
    local_1c.s.LowPart = 0;
    local_1c.s.HighPart = 0;
    uVar1 = rdtsc();
    local_14 = (undefined4)((ulonglong)uVar1 >> 0x20);
    local_10 = (int)uVar1;
    iVar3 = local_24.s.HighPart + (uint)(0xfffc2f6f < local_24.s.LowPart);
    if (-1 < iVar3) {
      if (0 < iVar3) goto LAB_005d54c7;
      do {
        if (local_24.s.LowPart + 250000 <= local_1c.s.LowPart) break;
LAB_005d54c7:
        do {
          QueryPerformanceCounter(&local_1c);
          iVar3 = local_24.s.HighPart + (uint)(0xfffc2f6f < local_24.s.LowPart);
        } while (local_1c.s.HighPart < iVar3);
      } while (local_1c.s.HighPart <= iVar3);
    }
    uVar1 = rdtsc();
    fVar4 = (float10)(uint)((int)uVar1 - local_10) *
            (float10)CONCAT44(local_2c.s.HighPart,local_2c.s.LowPart) * (float10)_DAT_00667898;
  }
  return fVar4;
}

