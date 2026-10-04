
DWORD FUN_005fd96f(void)

{
  LARGE_INTEGER local_c;
  
  QueryPerformanceFrequency(&local_c);
  return local_c.s.LowPart;
}

