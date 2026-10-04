
void FUN_00634dd0(uint param_1)

{
  int iVar1;
  uint dwBytes;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_00689220;
  puStack_10 = &LAB_006383d0;
  local_14 = ExceptionList;
  if (DAT_00703ffc == 3) {
    ExceptionList = &local_14;
    if (param_1 <= DAT_00703ff4) {
      ExceptionList = &local_14;
      FUN_0063d88b(9);
      local_8 = 0;
      iVar1 = FUN_0063fcf6(param_1);
      local_8 = 0xffffffff;
      FUN_00634e37();
      if (iVar1 != 0) {
        ExceptionList = local_14;
        return;
      }
    }
  }
  else {
    ExceptionList = &local_14;
    if (DAT_00703ffc == 2) {
      if (param_1 == 0) {
        dwBytes = 0x10;
      }
      else {
        dwBytes = param_1 + 0xf & 0xfffffff0;
      }
      ExceptionList = &local_14;
      if (dwBytes <= DAT_006dd354) {
        ExceptionList = &local_14;
        FUN_0063d88b(9);
        local_8 = 1;
        iVar1 = FUN_00640799(dwBytes >> 4);
        local_8 = 0xffffffff;
        FUN_00634e96();
        if (iVar1 != 0) {
          ExceptionList = local_14;
          return;
        }
      }
      goto LAB_00634eaf;
    }
  }
  if (param_1 == 0) {
    param_1 = 1;
  }
  dwBytes = param_1 + 0xf & 0xfffffff0;
LAB_00634eaf:
  HeapAlloc(DAT_00703ff8,0,dwBytes);
  ExceptionList = local_14;
  return;
}

