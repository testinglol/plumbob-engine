
void __thiscall FUN_005eccb4(int *param_1,undefined4 *param_2)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = *param_2;
  local_8 = param_2[1];
  local_14 = param_2[2];
  local_10 = param_2[3];
  (**(code **)(*param_1 + 0x114))(&local_c);
  (**(code **)(*param_1 + 0x114))(&local_14);
  *param_2 = local_c;
  param_2[1] = local_8;
  param_2[2] = local_14;
  param_2[3] = local_10;
  return;
}

