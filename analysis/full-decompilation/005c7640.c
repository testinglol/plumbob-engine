
uint __thiscall FUN_005c7640(int param_1,int *param_2)

{
  int *piVar1;
  
  piVar1 = param_2;
  FUN_006331bc(&param_2,4);
  if ((param_2 != (int *)0xb0b0b0b0) && (param_2 != (int *)0xb0b0b0b1)) {
    return 0x9b0d0017;
  }
  FUN_006331bc(param_1,0xc);
  FUN_006331bc(param_1 + 0xc,0xc);
  FUN_006331bc(param_1 + 0x18,4);
  FUN_006331bc(param_1 + 0x1c,0xc);
  FUN_006331bc(param_1 + 0x28,4);
  FUN_006331bc(param_1 + 0x2c,4);
  FUN_006331bc(param_1 + 0x30,4);
  FUN_006331bc(param_1 + 0x34,4);
  if (param_2 == (int *)0xb0b0b0b1) {
    FUN_006331bc(param_1 + 0x38,4);
    FUN_006331bc(param_1 + 0x3c,4);
    FUN_006331bc(param_1 + 0x40,4);
    FUN_006331bc(param_1 + 0x44,4);
  }
  else {
    *(undefined4 *)(param_1 + 0x44) = 0;
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  return -(uint)(*(int *)(*(int *)(*piVar1 + 4) + 8 + (int)piVar1) != 0) & 0x9b0d0012;
}

