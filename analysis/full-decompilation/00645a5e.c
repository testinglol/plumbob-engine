
void FUN_00645a5e(uint param_1)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_00704000)[(int)param_1 >> 5] + 0xc + (param_1 & 0x1f) * 0x24));
  return;
}

