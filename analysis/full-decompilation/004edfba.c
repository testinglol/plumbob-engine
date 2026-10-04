
void FUN_004edfba(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined **local_448 [3];
  undefined1 local_43c [260];
  undefined **local_338 [3];
  undefined1 local_32c [260];
  undefined **local_228 [3];
  undefined1 local_21c [260];
  undefined **local_118 [3];
  undefined1 local_10c [260];
  int local_8;
  
  FUN_0046f824(local_10c,0,0x104);
  local_118[0] = &PTR_FUN_006664e8;
  FUN_0046f824(local_21c,0,0x104);
  local_228[0] = &PTR_FUN_006664e8;
  FUN_0046f824(local_32c,0,0x104);
  local_338[0] = &PTR_FUN_006664e8;
  FUN_0046f824(local_43c,0,0x104);
  local_448[0] = &PTR_FUN_006664e8;
  if ((param_3 != 0) || (param_3 = FUN_004eda2e(), param_3 != 0)) {
    FUN_0046f847(param_3,0xffffffff);
    FUN_0041218d(local_118,local_228);
    FUN_00412209(local_228,local_338,local_448);
    FUN_0046f8e4(local_8 + 0x1c);
    FUN_0046f917(local_338,0xffffffff);
    FUN_0046f847(s__thumb_jpg_006c83cc,0xffffffff);
  }
  return;
}

