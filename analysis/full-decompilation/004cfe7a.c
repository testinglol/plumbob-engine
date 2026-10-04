
undefined4 __fastcall FUN_004cfe7a(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined **local_110;
  LPSTR local_10c;
  undefined1 local_104 [256];
  
  FUN_0046fb9b(local_104,0x100);
  local_110 = &PTR_LAB_0066655c;
  cVar1 = FUN_004074bc();
  if (cVar1 == '\0') {
    iVar2 = FUN_004e99a9();
    if (iVar2 != -1) {
      iVar2 = FUN_004e9744(iVar2);
      if (iVar2 != 0) {
        iVar2 = FUN_00425db3((int)*(short *)(iVar2 + 0x606));
        goto LAB_004cfef7;
      }
    }
  }
  else if (*DAT_006e486c != 0) {
    iVar2 = *(int *)(*DAT_006e486c + 0x10);
LAB_004cfef7:
    if (iVar2 != 0) {
      uVar3 = FUN_004102f3();
      goto LAB_004cff1e;
    }
  }
  uVar3 = 0;
LAB_004cff1e:
  wsprintfA(local_10c,(LPCSTR)&DAT_006c08e4,uVar3);
  FUN_0046f8e4(&local_110);
  return *(undefined4 *)(param_1 + 0x238);
}

