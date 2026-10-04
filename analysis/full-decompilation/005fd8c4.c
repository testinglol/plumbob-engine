
undefined8 FUN_005fd8c4(void)

{
  LARGE_INTEGER local_c;
  
  QueryPerformanceCounter(&local_c);
  return CONCAT44(local_c.s.HighPart,local_c.s.LowPart);
}

