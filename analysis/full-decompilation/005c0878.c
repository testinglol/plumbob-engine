
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_005c0878(undefined4 param_1)

{
  DAT_006fe66c = LoadLibraryA(s_shell32_dll_006d2b7c);
  if (DAT_006fe66c != (HMODULE)0x0) {
    _DAT_006fe668 = GetProcAddress(DAT_006fe66c,s_ShellExecuteA_006d2b6c);
  }
  return param_1;
}

