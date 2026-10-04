
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063884d(void)

{
  longlong lVar1;
  _FILETIME local_c;
  
  GetSystemTimeAsFileTime(&local_c);
  lVar1 = __allmul(local_c.dwHighDateTime,0,0,1);
  __aulldiv((lVar1 - CONCAT44(_DAT_00703b04,_DAT_00703b00)) + (ulonglong)local_c.dwLowDateTime,10000
            ,0);
  return;
}

