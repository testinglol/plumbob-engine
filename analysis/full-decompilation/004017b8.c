
void __fastcall FUN_004017b8(LONG *param_1)

{
  uint uVar1;
  uint uVar2;
  LONG LVar3;
  int iVar4;
  uint uVar5;
  DWORD dwMilliseconds;
  int local_c;
  
  LVar3 = InterlockedExchange(param_1,1);
  uVar2 = DAT_006c08e8;
  if (LVar3 != 0) {
    uVar5 = 0;
    if (DAT_006c08e8 != 0) {
      uVar1 = DAT_006de5a8 >> 1;
      do {
        if (((uVar1 <= uVar5) && (*param_1 == 0)) &&
           (LVar3 = InterlockedExchange(param_1,1), LVar3 == 0)) {
          DAT_006c08e8 = 1000;
          DAT_006de5a8 = uVar5;
          return;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar2);
    }
    DAT_006c08e8 = 0x1e;
    local_c = 6;
    while( true ) {
      iVar4 = local_c;
      if (0x1b < local_c) {
        iVar4 = 0x1b;
      }
      LVar3 = InterlockedExchange(param_1,1);
      if (LVar3 == 0) break;
      if (iVar4 < 0x15) {
        dwMilliseconds = 0;
      }
      else {
        dwMilliseconds = 1 << ((char)iVar4 - 0x14U & 0x1f);
      }
      Sleep(dwMilliseconds);
      local_c = local_c + 1;
    }
  }
  return;
}

