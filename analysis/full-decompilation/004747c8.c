
void __thiscall FUN_004747c8(ushort *param_1,undefined4 param_2)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 6) == 0) {
    FUN_0046f8cb(s_No_behavior_006c4d64);
  }
  else {
    if (*param_1 == 0xffff) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = *param_1 & 0x7fff;
    }
    FUN_00402122(uVar1,param_2);
  }
  return;
}

