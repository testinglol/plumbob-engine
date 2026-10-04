
uint __thiscall FUN_00422d79(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  FUN_00457da4();
  uVar1 = FUN_004561a0(param_2);
  if ((short)uVar1 == 0) {
    uVar1 = uVar1 & 0xffffff00;
  }
  else {
    uVar1 = FUN_00474b22(*(undefined4 *)(*(int *)(param_1 + 0x11c) + 0xc),param_3,uVar1,param_4);
  }
  return uVar1;
}

