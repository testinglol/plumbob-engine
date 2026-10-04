
void __thiscall FUN_0058669c(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 0x130) = *(int *)(param_1 + 0x130) + 1;
  *(int *)(param_1 + 0x150) = *(int *)(param_1 + 0x150) + 1;
  *(undefined4 *)(param_1 + 0x3c) = *param_2;
  *(undefined4 *)(param_1 + 0x40) = param_2[1];
  uVar1 = param_2[3];
  *(undefined4 *)(param_1 + 0x44) = param_2[2];
  *(undefined4 *)(param_1 + 0x48) = uVar1;
  return;
}

