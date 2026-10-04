
void __thiscall
FUN_00459152(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5)

{
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 4) == 0) {
    local_8 = 0;
    local_c = 0;
  }
  else {
    local_c = *(undefined4 *)(param_1 + 0x18);
    local_8 = *(undefined4 *)(param_1 + 0x1c);
  }
  if (param_2 == 0) {
    *param_3 = local_c;
    param_3[1] = local_8;
  }
  else {
    FUN_004643d8(param_2,&local_c,param_3);
  }
  FUN_0041fe32(param_1 + 0x10);
  FUN_0041fdff(0,*(undefined4 *)(param_1 + 0xc));
  *param_4 = *(undefined4 *)(param_1 + 0x24);
  *param_5 = *(undefined4 *)(param_1 + 0x28);
  return;
}

