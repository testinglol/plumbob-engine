
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004732f4(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  float10 fVar4;
  LARGE_INTEGER local_1c;
  LARGE_INTEGER local_14;
  LARGE_INTEGER local_c;
  
  if (DAT_006e5470 == '\0') {
    fVar4 = (float10)_DAT_006669e8;
  }
  else {
    QueryPerformanceFrequency(&local_1c);
    QueryPerformanceCounter(&local_14);
    local_c.s.LowPart = 0;
    local_c.s.HighPart = 0;
    uVar1 = rdtsc();
    iVar3 = local_14.s.HighPart + (uint)(0xfffc2f6f < local_14.s.LowPart);
    if (-1 < iVar3) {
      if (0 < iVar3) goto LAB_0047334e;
      do {
        if (local_14.s.LowPart + 250000 <= local_c.s.LowPart) break;
LAB_0047334e:
        do {
          QueryPerformanceCounter(&local_c);
          iVar3 = local_14.s.HighPart + (uint)(0xfffc2f6f < local_14.s.LowPart);
        } while (local_c.s.HighPart < iVar3);
      } while (local_c.s.HighPart <= iVar3);
    }
    uVar2 = rdtsc();
    fVar4 = (float10)(uint)((int)uVar2 - (int)uVar1) *
            (float10)(longlong)local_1c * (float10)_DAT_00667898;
  }
  return fVar4;
}

