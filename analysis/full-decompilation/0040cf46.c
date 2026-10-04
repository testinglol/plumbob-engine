
int FUN_0040cf46(void)

{
  int iVar1;
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
  FUN_0046f824(local_34,0,0x10);
  local_40[0] = &PTR_FUN_00666564;
  FUN_0046f847(s_dogmale_006c1060,0xffffffff);
  FUN_0046f824(local_6c,0,0x10);
  local_78[0] = &PTR_FUN_00666564;
  FUN_0046f847(s_dogfemale_006c1054,0xffffffff);
  FUN_0046f824(local_50,0,0x10);
  local_5c[0] = &PTR_FUN_00666564;
  FUN_0046f847(s_catmale_006c104c,0xffffffff);
  FUN_0046f824(local_88,0,0x10);
  local_94[0] = &PTR_FUN_00666564;
  FUN_0046f847(s_catfemale_006c1040,0xffffffff);
  iVar1 = FUN_0046f973(local_40);
  if ((iVar1 != 0) && (iVar1 = FUN_0046f973(local_78), iVar1 != 0)) {
    iVar1 = FUN_0046f973(local_5c);
    if (iVar1 == 0) {
      return 2;
    }
    iVar1 = FUN_0046f973(local_94);
    return (-(uint)(iVar1 != 0) & 0xfffffffe) + 2;
  }
  return 1;
}

