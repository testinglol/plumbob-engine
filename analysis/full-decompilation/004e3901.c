
int FUN_004e3901(int param_1)

{
  int iVar1;
  undefined4 local_10c;
  undefined1 local_104 [256];
  
  iVar1 = _rand();
  FUN_0046f824(local_104,0,0x100);
  FUN_0046f847(s_rand_006c9adc,0xffffffff);
  FUN_0046fa40(iVar1);
  FUN_0046f847(&DAT_006c08dc,0xffffffff);
  FUN_004e334f(local_10c);
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  return iVar1 % param_1;
}

