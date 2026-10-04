
void __thiscall FUN_0050ad4b(int *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  *param_1 = param_2;
  if (param_2 == 1) {
    uVar2 = 0x3f800000;
    uVar1 = 0;
  }
  else {
    if (param_2 == 2) {
      param_1[8] = param_1[4];
      param_1[9] = param_1[5];
      param_1[10] = param_1[6];
      param_1[0xb] = param_1[7];
      return;
    }
    if (param_2 != 3) {
      return;
    }
    uVar2 = 0;
    uVar1 = 0x3f800000;
  }
  FUN_004734bd(uVar1,uVar2,400,DAT_006e5490);
  return;
}

