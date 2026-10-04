
void __thiscall FUN_00592976(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 0x244);
  *param_2 = *(undefined4 *)(param_1 + 0x240);
  uVar2 = *(undefined4 *)(param_1 + 0x248);
  param_2[1] = uVar1;
  param_2[2] = uVar2;
  return;
}

