
void FUN_0063e341(void)

{
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_00689410;
  puStack_10 = &LAB_006383d0;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  if (PTR_FUN_006db314 != (undefined *)0x0) {
    local_8 = 1;
    ExceptionList = &pvStack_14;
    (*(code *)PTR_FUN_006db314)();
  }
  local_8 = 0xffffffff;
  FUN_0063e2e0();
  return;
}

