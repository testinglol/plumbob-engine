
void __thiscall FUN_0041ced8(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined **local_54 [3];
  undefined1 local_48 [64];
  undefined4 local_8;
  
  FUN_0046f824(local_48,0,0x40);
  local_54[0] = &PTR_FUN_0066651c;
  (**(code **)(*param_1 + 0x48))(param_2,local_54);
  uVar1 = (**(code **)(*param_1 + 0x58))(param_2);
  local_8 = CONCAT31(local_8._1_3_,uVar1);
  if (param_1[2] == 0) {
    (**(code **)(*param_1 + 0x84))(param_2,param_3,local_54,local_8);
  }
  return;
}

