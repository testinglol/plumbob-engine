
void FUN_0047edbb(short *param_1)

{
  undefined **local_110 [2];
  short local_108;
  undefined1 local_104 [256];
  
  FUN_0046fa24(0x28);
  FUN_0046f824(local_104,0,0x100);
  local_110[0] = &PTR_FUN_00666524;
  FUN_00465b21(local_110,*(undefined4 *)(DAT_006e486c + 0xc),0xd8,*param_1 + 1);
  if (local_108 == 0) {
    FUN_0046f847(s_type_006c52c8,0xffffffff);
    FUN_0046fa40((int)*param_1);
  }
  else {
    FUN_0046f917(local_110,0xffffffff);
  }
  FUN_0046fa24(0x29);
  return;
}

