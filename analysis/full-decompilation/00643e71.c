
LPVOID FUN_00643e71(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint _Size;
  LPVOID local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_00689c00;
  puStack_10 = &LAB_006383d0;
  local_14 = ExceptionList;
  uVar2 = param_1 * param_2;
  uVar3 = uVar2;
  ExceptionList = &local_14;
  if (uVar2 < 0xffffffe1) {
    if (uVar2 == 0) {
      uVar3 = 1;
    }
    uVar3 = uVar3 + 0xf & 0xfffffff0;
    ExceptionList = &local_14;
  }
  do {
    local_24 = (LPVOID)0x0;
    if (uVar3 < 0xffffffe1) {
      if (DAT_00703ffc == 3) {
        if (uVar2 <= DAT_00703ff4) {
          FUN_0063d88b(9);
          local_8 = 0;
          local_24 = (LPVOID)FUN_0063fcf6(uVar2);
          local_8 = 0xffffffff;
          FUN_00643f0a();
          _Size = uVar2;
          if (local_24 == (void *)0x0) goto LAB_00643f5e;
LAB_00643f4d:
          _memset(local_24,0,_Size);
        }
LAB_00643f59:
        if (local_24 != (LPVOID)0x0) {
          ExceptionList = local_14;
          return local_24;
        }
      }
      else {
        if ((DAT_00703ffc != 2) || (DAT_006dd354 < uVar3)) goto LAB_00643f59;
        FUN_0063d88b(9);
        local_8 = 1;
        local_24 = (LPVOID)FUN_00640799(uVar3 >> 4);
        local_8 = 0xffffffff;
        FUN_00643f93();
        _Size = uVar3;
        if (local_24 != (void *)0x0) goto LAB_00643f4d;
      }
LAB_00643f5e:
      local_24 = HeapAlloc(DAT_00703ff8,8,uVar3);
    }
    if (local_24 != (LPVOID)0x0) {
      ExceptionList = local_14;
      return local_24;
    }
    if (DAT_00703bbc == 0) {
      ExceptionList = local_14;
      return (LPVOID)0x0;
    }
    iVar1 = FUN_0063f76d(uVar3);
    if (iVar1 == 0) {
      ExceptionList = local_14;
      return (LPVOID)0x0;
    }
  } while( true );
}

