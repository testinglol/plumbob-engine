
void __thiscall
FUN_004ccf5b(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x24) = 3;
  FUN_005a5e48(0);
  *(int *)(param_1 + 0x40) = param_2;
  if ((((param_2 != 2) && (param_2 != 0xc)) && (param_2 != 0xd)) && (param_2 != 0xe)) {
    *(undefined4 *)(param_1 + 0x3c) = 0;
    goto LAB_004ccfbe;
  }
  if (param_2 == 2) {
LAB_004ccfb0:
    uVar1 = 0xf8;
  }
  else if (param_2 == 0xc) {
    uVar1 = 0xf9;
  }
  else if (param_2 == 0xd) {
    uVar1 = 0xfa;
  }
  else {
    if (param_2 != 0xe) goto LAB_004ccfb0;
    uVar1 = 0xfb;
  }
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
LAB_004ccfbe:
  *(undefined4 *)(param_1 + 0x38) = 2;
  FUN_005d499c(param_3);
  FUN_005d499c(param_4);
  *(undefined4 *)(param_1 + 0x1c) = param_5;
  FUN_004cc877(0,4);
  return;
}

