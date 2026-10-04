
void __thiscall FUN_005d77e6(int *param_1,undefined4 param_2)

{
  int iVar1;
  void *_Dst;
  undefined4 uVar2;
  
  iVar1 = FUN_005d49d6();
  FUN_005d499c(param_2);
  (**(code **)(*param_1 + 0x168))();
  FUN_006321f0(param_1[0x37]);
  param_1[0x37] = 0;
  if (iVar1 != 0) {
    _Dst = operator_new(iVar1 + 1U);
    param_1[0x37] = (int)_Dst;
    _memset(_Dst,0,iVar1 + 1U);
    uVar2 = FUN_004096c2(iVar1);
    (*(code *)PTR_FUN_006d7050)(param_1[0x37],uVar2);
    if (DAT_006fe8cc != (HWND)0x0) {
      SetWindowTextA(DAT_006fe8cc,(LPCSTR)param_1[0x37]);
    }
  }
  return;
}

