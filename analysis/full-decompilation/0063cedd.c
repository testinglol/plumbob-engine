
void FUN_0063cedd(uint param_1)

{
  if ((0x6dae2f < param_1) && (param_1 < 0x6db091)) {
    FUN_0063d88b(((int)(param_1 - 0x6dae30) >> 5) + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}

