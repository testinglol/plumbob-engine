
undefined4 __fastcall FUN_005fbc0c(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_c = param_1;
  uStack_8 = param_1;
  FUN_005b8f4a(0x24);
  local_c = DAT_006d8240;
  uStack_8 = CONCAT31((int3)(uStack_8 >> 8),DAT_006d8244) & 0xffffff;
  do {
    iVar2 = FUN_005b8e6a((int)&local_c + 3,1);
    if (iVar2 != 1) {
      return 0;
    }
    if (((((char)local_c == 'd') && (local_c._1_1_ == 'a')) && (local_c._2_1_ == 't')) &&
       (local_c._3_1_ == 'a')) {
      uStack_8 = CONCAT13(1,(undefined3)uStack_8);
    }
    uVar1 = (uint)local_c >> 8;
    local_c = CONCAT22(CONCAT11(local_c._3_1_,local_c._3_1_),(short)uVar1);
  } while (uStack_8._3_1_ == '\0');
  FUN_005b8e6a(param_1 + 0x1c,4);
  return 1;
}

