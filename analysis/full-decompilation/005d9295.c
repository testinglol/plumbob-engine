
void __fastcall FUN_005d9295(undefined4 *param_1)

{
  param_1[-1] = &PTR_LAB_00673adc;
  *param_1 = &PTR_FUN_00673af8;
  if ((HANDLE)param_1[0xb] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0xb]);
  }
  param_1 = (undefined4 *)(-(uint)(param_1 != (undefined4 *)0x4) & (uint)param_1);
  *param_1 = &PTR_FUN_00673858;
  param_1[1] = &PTR_LAB_00673ab8;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  return;
}

