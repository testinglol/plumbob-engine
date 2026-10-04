
void FUN_00570f5d(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = *param_1;
  local_c = param_1[1];
  FUN_0047bd91(&local_8,&local_c,*(undefined4 *)(DAT_006e54d8 + 0x84),0x400);
  uVar1 = FUN_004a6a46(&local_c,param_1[2]);
  param_1._2_2_ = (short)((uint)uVar1 >> 0x10);
  *param_2 = (int)param_1._2_2_;
  param_1._0_2_ = (short)uVar1;
  param_2[1] = (int)(short)param_1;
  return;
}

