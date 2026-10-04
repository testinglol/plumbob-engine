
void __fastcall FUN_0046daf2(int param_1)

{
  char cVar1;
  int iVar2;
  BOOL BVar3;
  tagMSG local_1c;
  
  cVar1 = FUN_004074bc();
  if (cVar1 == '\x01') {
    cVar1 = FUN_00442fdb();
    if (cVar1 == '\0') {
      FUN_0046d8ac(1000);
    }
    else {
      FUN_0046d8f7();
    }
  }
  iVar2 = DAT_006e5490;
  if (*(int *)(param_1 + 0xb8) == 0) {
    *(undefined4 *)(param_1 + 0xbc) = *(undefined4 *)(param_1 + 0xc0);
  }
  else {
    *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + (DAT_006e5490 - *(int *)(param_1 + 0xb8));
  }
  *(int *)(param_1 + 0xb8) = iVar2;
  while( true ) {
    FUN_004733e4(iVar2);
    if (*(int *)(param_1 + 0xbc) < *(int *)(param_1 + 0xc0)) {
      return;
    }
    iVar2 = FUN_00473417();
    if (iVar2 == 0) {
      return;
    }
    *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) - *(int *)(param_1 + 0xc0);
    FUN_0046d461();
    if ((*(char *)(param_1 + 0xd4) != '\0') &&
       (BVar3 = PeekMessageA(&local_1c,(HWND)0x0,0,0,0), BVar3 != 0)) {
      return;
    }
    if (DAT_006e5458 != '\0') {
      return;
    }
    if (*(short *)(param_1 + 0x26) != 0) break;
    FUN_0046dd08();
    iVar2 = DAT_006e5490;
    if (*(char *)(param_1 + 0xe0) == '\x01') {
      FUN_004f277c();
      *(undefined1 *)(param_1 + 0xe0) = 0;
      iVar2 = DAT_006e5490;
    }
  }
  *(undefined2 *)(param_1 + 0x26) = 0;
  return;
}

