
void __thiscall FUN_004ceec9(int param_1,undefined4 param_2,int param_3)

{
  *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) | 0x10;
  *(undefined4 *)(param_1 + 0x34) = param_2;
  if (param_3 == 0) {
    FUN_004a7da6(param_2,0,1);
    FUN_0057ac7f();
  }
  return;
}

