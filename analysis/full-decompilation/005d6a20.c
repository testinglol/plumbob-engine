
void FUN_005d6a20(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  int *piVar1;
  
  if (DAT_006fefd0 == '\0') {
    piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
    (**(code **)(*piVar1 + 8))();
    FUN_005d6a69(param_1,param_2,param_3,param_4);
  }
  else {
    DefWindowProcA(param_1,param_2,param_3,param_4);
  }
  return;
}

