
void __thiscall FUN_004b4b7d(int param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int local_c;
  int iStack_8;
  
  *(undefined4 *)(param_1 + 4) = *param_2;
  *(undefined4 *)(param_1 + 8) = param_2[1];
  *(undefined4 *)(param_1 + 0xc) = param_2[2];
  local_c = param_1;
  iStack_8 = param_1;
  puVar1 = (undefined4 *)FUN_00454ff9(&local_c,(undefined4 *)(param_1 + 4));
  *(undefined4 *)(param_1 + 0x10) = *puVar1;
  *(undefined4 *)(param_1 + 0x14) = puVar1[1];
  *(undefined4 *)(param_1 + 0x18) = param_3;
  return;
}

