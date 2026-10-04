
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  DWORD DVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  HMODULE pHVar5;
  undefined4 uVar6;
  _STARTUPINFOA local_60;
  undefined1 *local_1c;
  undefined4 *local_18;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_00689360;
  puStack_10 = &LAB_006383d0;
  pvStack_14 = ExceptionList;
  local_1c = &stack0xffffff88;
  ExceptionList = &pvStack_14;
  DVar1 = GetVersion();
  _DAT_00703ac0 = DVar1 >> 8 & 0xff;
  _DAT_00703abc = DVar1 & 0xff;
  _DAT_00703ab8 = _DAT_00703abc * 0x100 + _DAT_00703ac0;
  _DAT_00703ab4 = DVar1 >> 0x10;
  iVar2 = FUN_0063f8fd(1);
  if (iVar2 == 0) {
    FUN_006383a1(0x1c);
  }
  iVar2 = FUN_0063e16c();
  if (iVar2 == 0) {
    FUN_006383a1(0x10);
  }
  local_8 = 0;
  FUN_0063d567();
  DAT_00705348 = GetCommandLineA();
  DAT_00703af4 = FUN_00644947();
  FUN_006446fa();
  FUN_00644641();
  FUN_00637c9d();
  local_60.dwFlags = 0;
  GetStartupInfoA(&local_60);
  uVar3 = FUN_006445e9();
  if ((local_60.dwFlags & 1) == 0) {
    uVar4 = 10;
  }
  else {
    uVar4 = (uint)local_60.wShowWindow;
  }
  uVar6 = 0;
  pHVar5 = GetModuleHandleA((LPCSTR)0x0);
  uVar3 = FUN_004eeb12(pHVar5,uVar6,uVar3,uVar4);
  FUN_00637cca(uVar3);
  FUN_00643fae(*(undefined4 *)*local_18,local_18);
  return;
}

