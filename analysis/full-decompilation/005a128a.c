
void __thiscall FUN_005a128a(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + 1;
  *(undefined4 *)(param_1 + 0xbc) = *param_2;
  *(undefined4 *)(param_1 + 0xc0) = param_2[1];
  *(undefined4 *)(param_1 + 0xc4) = param_2[2];
  *(undefined4 *)(param_1 + 200) = param_2[3];
  uVar1 = param_2[5];
  *(undefined4 *)(param_1 + 0xcc) = param_2[4];
  *(undefined4 *)(param_1 + 0xd0) = uVar1;
  return;
}

