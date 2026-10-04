
undefined2 FUN_005e34c5(undefined4 param_1,uint param_2,uint param_3,uint param_4,int param_5)

{
  undefined2 uVar1;
  uint uVar2;
  
  if (param_5 != 0) {
    uVar2 = (param_4 & 0xff) + param_5;
    if ((int)uVar2 < 0) {
      param_4 = 0;
    }
    else {
      param_4 = 0xff;
      if ((int)uVar2 < 0x100) {
        param_4 = uVar2 & 0xff;
      }
    }
    uVar2 = (param_3 & 0xff) + param_5;
    if ((int)uVar2 < 0) {
      param_3 = 0;
    }
    else {
      param_3 = 0xff;
      if ((int)uVar2 < 0x100) {
        param_3 = uVar2 & 0xff;
      }
    }
    uVar2 = (param_2 & 0xff) + param_5;
    if ((int)uVar2 < 0) {
      param_2 = 0;
    }
    else {
      param_2 = 0xff;
      if ((int)uVar2 < 0x100) {
        param_2 = uVar2 & 0xff;
      }
    }
  }
  uVar1 = FUN_005dfe3b(param_2,param_3,param_4);
  return uVar1;
}

