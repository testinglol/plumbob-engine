
void __thiscall FUN_005e7846(int param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  undefined4 uVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  int local_8;
  
  uVar1 = param_2;
  FUN_00601485(&local_8,&param_2);
  if ((local_8 != *(int *)(param_1 + 0x28)) &&
     (*(undefined4 **)(local_8 + 0x14) != (undefined4 *)0x0)) {
    (**(code **)**(undefined4 **)(local_8 + 0x14))(1);
  }
  local_c = CONCAT31(local_c._1_3_,param_4);
  local_18 = param_3;
  local_14 = local_c;
  local_1c = uVar1;
  FUN_005e843d(local_10,&local_1c);
  return;
}

