
void FUN_0048befd(int param_1,int param_2,char param_3)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  *(uint *)(param_1 + 0x24) = (param_3 != '\0') + 6;
  if (param_2 < 0) {
    FUN_00492bba(-param_2);
  }
  else {
    FUN_00492bb0(param_2);
  }
  FUN_00492bc4();
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  return;
}

