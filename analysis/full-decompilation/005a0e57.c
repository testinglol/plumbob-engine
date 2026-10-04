
void __thiscall FUN_005a0e57(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffffe;
  *(undefined4 *)(param_1 + 0x68) = *param_2;
  *(undefined4 *)(param_1 + 0x6c) = param_2[1];
  *(undefined4 *)(param_1 + 0x70) = param_2[2];
  *(undefined4 *)(param_1 + 0x74) = param_2[3];
  uVar1 = param_2[5];
  *(undefined4 *)(param_1 + 0x78) = param_2[4];
  *(undefined4 *)(param_1 + 0x7c) = uVar1;
  return;
}

