
SIZE_T FUN_00640e9d(LPCVOID param_1)

{
  byte *pbVar1;
  SIZE_T SVar2;
  undefined1 local_30 [4];
  byte *local_2c;
  undefined1 local_28 [4];
  SIZE_T local_24;
  byte *local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_006894e8;
  puStack_10 = &LAB_006383d0;
  local_14 = ExceptionList;
  if (DAT_00703ffc == 3) {
    ExceptionList = &local_14;
    FUN_0063d88b(9);
    local_8 = 0;
    local_20 = (byte *)FUN_0063f9a2(param_1);
    if (local_20 != (byte *)0x0) {
      local_24 = *(int *)((int)param_1 + -4) - 9;
    }
    SVar2 = local_24;
    local_8 = 0xffffffff;
    FUN_00640f07();
    pbVar1 = local_20;
  }
  else {
    ExceptionList = &local_14;
    if (DAT_00703ffc != 2) goto LAB_00640f5b;
    ExceptionList = &local_14;
    FUN_0063d88b(9);
    local_8 = 1;
    local_2c = (byte *)FUN_006406fd(param_1,local_30,local_28);
    if (local_2c != (byte *)0x0) {
      local_24 = (uint)*local_2c << 4;
    }
    SVar2 = local_24;
    local_8 = 0xffffffff;
    FUN_00640f82();
    pbVar1 = local_2c;
  }
  if (pbVar1 != (byte *)0x0) {
    ExceptionList = local_14;
    return SVar2;
  }
LAB_00640f5b:
  SVar2 = HeapSize(DAT_00703ff8,0,param_1);
  ExceptionList = local_14;
  return SVar2;
}

