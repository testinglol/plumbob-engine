
bool FUN_005a55f6(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006f7690);
  *param_3 = 0;
  iVar1 = FUN_004dee6e(param_1,param_2,param_4);
  *param_3 = iVar1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006f7690);
  return *param_3 != 0;
}

