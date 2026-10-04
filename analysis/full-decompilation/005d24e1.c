
undefined4 FUN_005d24e1(int *param_1,int param_2,undefined4 param_3)

{
  undefined4 local_10c;
  undefined1 local_108 [256];
  int *local_8;
  
  (**(code **)(*param_1 + 4))();
  local_10c = param_3;
  if (param_2 == 0) {
    local_108[0] = 0;
  }
  else {
    FUN_006358b0(local_108,param_2);
  }
  local_8 = param_1;
  FUN_005d2551(&local_10c);
  return 0;
}

