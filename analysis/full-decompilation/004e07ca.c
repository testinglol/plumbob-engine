
undefined4 __fastcall FUN_004e07ca(undefined4 param_1)

{
  undefined1 *puVar1;
  
  DAT_006f2234 = SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)&LAB_004e0821);
  GetModuleFileNameA((HMODULE)0x0,&DAT_006f2238,0x104);
  puVar1 = (undefined1 *)FUN_006375b5(&DAT_006f2238,0x2e);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 0;
    FUN_006358c0(puVar1,s__stkdmp_txt_006c91c8);
  }
  return param_1;
}

