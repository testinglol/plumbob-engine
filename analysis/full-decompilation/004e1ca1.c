
undefined4 FUN_004e1ca1(int param_1,int param_2,char param_3)

{
  undefined4 uVar1;
  undefined **local_110;
  undefined4 local_10c;
  undefined1 local_104 [256];
  
  FUN_0046f824(local_104,0,0x100);
  local_110 = &PTR_FUN_00666524;
  FUN_004102d4(&local_110);
  FUN_005d4bbf(local_10c);
  uVar1 = FUN_00410304();
  *(undefined4 *)(param_2 + 0x10) = 0;
  *(undefined4 *)(param_2 + 0xc) = uVar1;
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_1 + 0x110);
  uVar1 = FUN_00410315();
  *(undefined4 *)(param_2 + 0x18) = uVar1;
  if (param_3 != '\0') {
    uVar1 = FUN_004102f3();
    *(undefined4 *)(param_2 + 0x10) = uVar1;
  }
  return 1;
}

