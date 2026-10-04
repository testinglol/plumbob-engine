
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00638890(void)

{
  longlong lVar1;
  _FILETIME local_c;
  
  GetSystemTimeAsFileTime(&local_c);
  lVar1 = __allmul(local_c.dwHighDateTime,0,0,1);
  _DAT_00703b00 = lVar1 + (ulonglong)local_c.dwLowDateTime;
  return;
}

