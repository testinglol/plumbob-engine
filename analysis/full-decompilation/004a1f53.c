
bool __thiscall FUN_004a1f53(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined **local_224 [3];
  undefined1 local_218 [260];
  undefined **local_114 [3];
  undefined1 local_108 [260];
  
  FUN_0046f824(local_218,0,0x104);
  local_224[0] = &PTR_FUN_006664e8;
  FUN_0046f824(local_108,0,0x104);
  local_114[0] = &PTR_FUN_006664e8;
  (**(code **)(*(int *)*param_2 + 0x24))(local_114);
  FUN_0041218d(local_114,local_224);
  iVar1 = FUN_0046f973(param_1 + 4);
  return iVar1 == 0;
}

