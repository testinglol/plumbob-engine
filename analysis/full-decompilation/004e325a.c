
void FUN_004e325a(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_330 [260];
  undefined **local_22c [3];
  undefined1 local_220 [260];
  undefined **local_11c [3];
  undefined1 local_110 [260];
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = *(undefined4 *)(DAT_006e486c + 0x24);
  local_8 = *(undefined4 *)(DAT_006f2a08 + 0xb0);
  iVar1 = FUN_00428886();
  if (iVar1 != 0) {
    FUN_0042888d();
  }
  FUN_0046f824(local_110,0,0x104);
  local_11c[0] = &PTR_FUN_006664e8;
  FUN_0046f824(local_220,0,0x104);
  local_22c[0] = &PTR_FUN_006664e8;
  FUN_0046f824(local_330,0,0x104);
  uVar2 = FUN_0041532c(0x55,0,local_11c);
  FUN_004eea6b(uVar2);
  uVar2 = FUN_0041532c(0x56,local_22c);
  uVar2 = FUN_0041532c(7,uVar2);
  FUN_004ee9ce(uVar2);
  FUN_00560763(local_11c);
  FUN_004dd9c4(local_22c,local_11c,local_c,local_8);
  return;
}

