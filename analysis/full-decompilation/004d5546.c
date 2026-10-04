
void __thiscall FUN_004d5546(int param_1,char *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x78);
  *param_2 = *param_2 - (char)*(undefined4 *)(param_1 + 0x70);
  param_2[1] = param_2[1] - (char)uVar1;
  return;
}

