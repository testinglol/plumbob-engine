
void __thiscall FUN_00463049(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffffe;
  *(undefined4 *)(param_1 + 0xf8) = *param_2;
  *(undefined4 *)(param_1 + 0xfc) = param_2[1];
  *(undefined4 *)(param_1 + 0x100) = param_2[2];
  *(undefined4 *)(param_1 + 0x104) = param_2[3];
  uVar1 = param_2[5];
  *(undefined4 *)(param_1 + 0x108) = param_2[4];
  *(undefined4 *)(param_1 + 0x10c) = uVar1;
  return;
}

