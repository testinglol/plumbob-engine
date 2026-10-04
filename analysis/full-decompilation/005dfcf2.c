
void __thiscall FUN_005dfcf2(int *param_1,int param_2)

{
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  local_14 = 0;
  local_10 = 0;
  if (*(int *)(param_2 + 0x1c) - *(int *)(param_2 + 0x14) < param_1[7] - param_1[5]) {
    local_c = *(int *)(param_2 + 0x1c) - *(int *)(param_2 + 0x14);
  }
  else {
    local_c = param_1[7] - param_1[5];
  }
  if (*(int *)(param_2 + 0x20) - *(int *)(param_2 + 0x18) < param_1[8] - param_1[6]) {
    local_8 = *(int *)(param_2 + 0x20) - *(int *)(param_2 + 0x18);
  }
  else {
    local_8 = param_1[8] - param_1[6];
  }
  (**(code **)(*param_1 + 0x20))(0x10);
  (**(code **)(*param_1 + 0x9c))(param_2,&local_14,&local_14,0);
  (**(code **)(*param_1 + 0x24))(0x10);
  return;
}

