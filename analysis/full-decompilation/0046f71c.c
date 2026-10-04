
int FUN_0046f71c(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  undefined **local_34c [3];
  undefined1 local_340 [260];
  undefined **local_23c [3];
  undefined1 local_230 [260];
  undefined **local_12c [3];
  undefined1 local_120 [260];
  undefined **local_1c [3];
  undefined1 local_10 [12];
  
  iVar2 = FUN_0046b693(param_1,param_2);
  if (iVar2 == 0) {
    sVar1 = FUN_004066d0();
    iVar2 = (int)sVar1;
    while (iVar2 = iVar2 + -1, -1 < iVar2) {
      FUN_0046f824(local_120,0,0x104);
      local_12c[0] = &PTR_FUN_006664e8;
      FUN_0046f824(local_340,0,0x104);
      local_34c[0] = &PTR_FUN_006664e8;
      FUN_0046f824(local_230,0,0x104);
      local_23c[0] = &PTR_FUN_006664e8;
      piVar3 = (int *)FUN_004066e7(iVar2);
      (**(code **)(*piVar3 + 0x24))(local_12c);
      FUN_00412209(local_12c,local_34c,local_23c);
      FUN_0046f824(local_10,0,5);
      local_1c[0] = &PTR_FUN_00667850;
      FUN_0046f847(&DAT_006c2648,0xffffffff);
      FUN_0046f973(local_1c);
    }
    iVar2 = 0;
  }
  return iVar2;
}

