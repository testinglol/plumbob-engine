
void FUN_00449cfc(int param_1,int param_2,undefined4 param_3)

{
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_1 != param_2) {
    local_8 = 0;
    for (local_c = param_2 - param_1 >> 2; local_c != 1; local_c = local_c >> 1) {
      local_8 = local_8 + 1;
    }
    FUN_0044a0b4(param_1,param_2,0,local_8 << 1,param_3);
    FUN_0044a160(param_1,param_2,param_3);
  }
  return;
}

