
void FUN_0063cf2f(uint param_1)

{
  if ((0x6dae2f < param_1) && (param_1 < 0x6db091)) {
    FUN_0063d8ec(((int)(param_1 - 0x6dae30) >> 5) + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}

