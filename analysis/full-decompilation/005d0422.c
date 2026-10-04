
void __thiscall FUN_005d0422(int param_1,undefined4 *param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x90) = *param_2;
  *(undefined4 *)(param_1 + 0x94) = param_2[1];
  *(undefined4 *)(param_1 + 0x98) = param_2[2];
  FUN_005d0456(param_2,param_3);
  FUN_005d04ff();
  return;
}

