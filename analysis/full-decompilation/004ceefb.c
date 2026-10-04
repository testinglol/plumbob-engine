
void __thiscall FUN_004ceefb(int param_1,undefined4 param_2,int param_3)

{
  *(undefined4 *)(param_1 + 0x38) = param_2;
  if (param_3 == 0) {
    FUN_004a8012(param_2,0,1);
  }
  *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) | 8;
  FUN_004cefd8();
  return;
}

