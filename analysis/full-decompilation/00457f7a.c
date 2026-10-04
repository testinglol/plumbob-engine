
void __fastcall FUN_00457f7a(undefined4 *param_1)

{
  undefined **local_224 [3];
  undefined1 local_218 [260];
  undefined **local_114 [3];
  undefined1 local_108 [260];
  
  FUN_0046f824(local_108,0,0x104);
  local_114[0] = &PTR_FUN_006664e8;
  FUN_0046f824(local_218,0,0x104);
  local_224[0] = &PTR_FUN_006664e8;
  (**(code **)(*(int *)*param_1 + 0x24))(local_114);
  FUN_0041218d(local_114,local_224);
  FUN_0046f8e4(local_224);
  return;
}

