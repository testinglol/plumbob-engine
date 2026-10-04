
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00637e28(DWORD *param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  undefined4 uVar3;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_00689350;
  puStack_10 = &LAB_006383d0;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  BVar1 = TlsSetValue(DAT_006db310,param_1);
  if (BVar1 == 0) {
    __amsg_exit(0x10);
  }
  DVar2 = GetCurrentThreadId();
  *param_1 = DVar2;
  if (_DAT_006da904 != (code *)0x0) {
    (*_DAT_006da904)();
  }
  local_8 = 0;
  uVar3 = (*(code *)param_1[0x12])(param_1[0x13]);
  FUN_00637ec4(uVar3);
  ExceptionList = local_14;
  return 0;
}

