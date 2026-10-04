
void FUN_0044a160(int param_1,int param_2,undefined4 param_3)

{
  undefined4 local_44;
  undefined4 local_8;
  
  if (param_2 - param_1 >> 2 < 0x11) {
    local_44 = param_1;
    if (param_1 != param_2) {
      while (local_44 = local_44 + 4, local_44 != param_2) {
        FUN_0044a6d4(param_1,local_44,0,param_3);
      }
    }
  }
  else {
    local_8 = param_1;
    if (param_1 != param_1 + 0x40) {
      while (local_8 = local_8 + 4, local_8 != param_1 + 0x40) {
        FUN_0044a6d4(param_1,local_8,0,param_3);
      }
    }
    FUN_0044a7a2(param_1 + 0x40,param_2,0,param_3);
  }
  return;
}

