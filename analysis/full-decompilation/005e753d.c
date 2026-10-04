
undefined4 __thiscall FUN_005e753d(uint param_1,undefined4 param_2,char param_3)

{
  undefined4 uVar1;
  uint local_8;
  
  local_8 = param_1;
  FUN_005e76d4(&local_8,&param_2);
  if (local_8 == *(uint *)(param_1 + 4)) {
    uVar1 = 0;
  }
  else {
    if ((param_3 != '\0') && (*(undefined4 **)(local_8 + 0x14) != (undefined4 *)0x0)) {
      (**(code **)**(undefined4 **)(local_8 + 0x14))(1);
    }
    FUN_006043cb(local_8);
    uVar1 = 1;
  }
  return uVar1;
}

