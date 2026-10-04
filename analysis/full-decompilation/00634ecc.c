
void FUN_00634ecc(LPVOID param_1)

{
  int iVar1;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  int local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_00689238;
  puStack_10 = &LAB_006383d0;
  local_14 = ExceptionList;
  if (param_1 == (LPVOID)0x0) {
    return;
  }
  if (DAT_00703ffc == 3) {
    ExceptionList = &local_14;
    FUN_0063d88b(9);
    local_8 = 0;
    local_20 = FUN_0063f9a2(param_1);
    if (local_20 != 0) {
      FUN_0063f9cd(local_20,param_1);
    }
    local_8 = 0xffffffff;
    FUN_00634f36();
    iVar1 = local_20;
  }
  else {
    ExceptionList = &local_14;
    if (DAT_00703ffc != 2) goto LAB_00634f98;
    ExceptionList = &local_14;
    FUN_0063d88b(9);
    local_8 = 1;
    local_28 = FUN_006406fd(param_1,&local_2c,&local_24);
    if (local_28 != 0) {
      FUN_00640754(local_2c,local_24,local_28);
    }
    local_8 = 0xffffffff;
    FUN_00634f8e();
    iVar1 = local_28;
  }
  if (iVar1 != 0) {
    ExceptionList = local_14;
    return;
  }
LAB_00634f98:
  HeapFree(DAT_00703ff8,0,param_1);
  ExceptionList = local_14;
  return;
}

