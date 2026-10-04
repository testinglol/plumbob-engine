
void __thiscall FUN_00457422(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined **local_50 [3];
  undefined1 local_44 [64];
  
  uVar1 = (**(code **)(*(int *)*param_1 + 0x38))(0x4f424a44,(int)param_1[0x2d] >> 0x10,FUN_0042004f)
  ;
  FUN_0046f824(local_44,0,0x40);
  local_50[0] = &PTR_FUN_0066651c;
  FUN_0046f847(param_2,0xffffffff);
  (**(code **)(*(int *)*param_1 + 0x84))(uVar1,(int)param_1[0x2d] >> 0x10,local_50,0);
  (**(code **)(*(int *)*param_1 + 0x7c))(uVar1);
  FUN_0046f8cb(param_2);
  FUN_00465a06(uVar1);
  FUN_0040766a(0x82,*(undefined4 *)(param_1[0x18] + 0x1c));
  return;
}

