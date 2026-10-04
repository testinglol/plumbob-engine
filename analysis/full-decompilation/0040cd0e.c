
char FUN_0040cd0e(void)

{
  int iVar1;
  char cVar2;
  undefined1 local_c0 [16];
  undefined **local_b0 [3];
  undefined1 local_a4 [16];
  undefined **local_94 [3];
  undefined1 local_88 [16];
  undefined **local_78 [3];
  undefined1 local_6c [16];
  undefined **local_5c [3];
  undefined1 local_50 [16];
  undefined **local_40 [3];
  undefined1 local_34 [16];
  undefined **local_24;
  undefined1 local_18 [16];
  undefined4 local_8;
  
  local_8 = FUN_004705f2(0xd,0xffffffff);
  FUN_0046f824(local_18,0,0x10);
  local_24 = &PTR_FUN_00666564;
  FUN_0046f847(local_8,0xffffffff);
  FUN_0046f824(local_6c,0,0x10);
  local_78[0] = &PTR_FUN_00666564;
  FUN_0046f847(&DAT_006c1070,0xffffffff);
  FUN_0046f824(local_34,0,0x10);
  local_40[0] = &PTR_FUN_00666564;
  FUN_0046f847(s_female_006c1068,0xffffffff);
  FUN_0046f824(local_a4,0,0x10);
  local_b0[0] = &PTR_FUN_00666564;
  FUN_0046f847(s_dogmale_006c1060,0xffffffff);
  FUN_0046f824(local_50,0,0x10);
  local_5c[0] = &PTR_FUN_00666564;
  FUN_0046f847(s_dogfemale_006c1054,0xffffffff);
  FUN_0046f824(local_88,0,0x10);
  local_94[0] = &PTR_FUN_00666564;
  FUN_0046f847(s_catmale_006c104c,0xffffffff);
  FUN_0046f824(local_c0,0,0x10);
  FUN_0046f847(s_catfemale_006c1040,0xffffffff);
  iVar1 = FUN_0046f973(local_78);
  if (iVar1 == 0) {
    return '\0';
  }
  iVar1 = FUN_0046f973(local_40);
  if (iVar1 == 0) {
    cVar2 = '\x01';
  }
  else {
    iVar1 = FUN_0046f973(local_b0);
    if (iVar1 == 0) {
      cVar2 = '\x02';
    }
    else {
      iVar1 = FUN_0046f973(local_5c);
      if (iVar1 != 0) {
        iVar1 = FUN_0046f973(local_94);
        return (iVar1 != 0) + '\x04';
      }
      cVar2 = '\x03';
    }
  }
  return cVar2;
}

