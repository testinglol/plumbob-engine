
uint __thiscall
FUN_004a156c(int *param_1,undefined4 param_2,int param_3,undefined4 *param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  uint uVar2;
  int *local_8;
  
  local_8 = param_1;
  FUN_00601485(&local_8,&param_2);
  if (local_8 == (int *)*param_1) {
    uVar2 = (uint)local_8 & 0xffffff00;
  }
  else {
    *param_4 = *(undefined4 *)(param_1[9] + 4 + *(int *)local_8[5] * 8);
    uVar1 = *(undefined4 *)(local_8[5] + param_3 * 4);
    *param_5 = uVar1;
    uVar2 = CONCAT31((int3)((uint)uVar1 >> 8),1);
  }
  return uVar2;
}

