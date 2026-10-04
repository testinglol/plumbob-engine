
void FUN_0063e2e0(void)

{
  int iVar1;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_006893f8;
  puStack_10 = &LAB_006383d0;
  pvStack_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &pvStack_14;
  iVar1 = FUN_0063e1d3();
  if (*(int *)(iVar1 + 0x60) != 0) {
    local_8 = 1;
    iVar1 = FUN_0063e1d3();
    (**(code **)(iVar1 + 0x60))();
  }
  local_8 = 0xffffffff;
  FUN_00646953();
  return;
}

