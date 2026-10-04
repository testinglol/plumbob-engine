
int FUN_004ea95f(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_004ea908(param_1);
  if (iVar1 != 0) {
    if (param_2 == 10) {
      uVar3 = 1;
    }
    else if (param_2 == 0xb) {
      uVar3 = 3;
    }
    else if (param_2 == 0xc) {
      uVar3 = 2;
    }
    else if (param_2 == 0xf) {
      uVar3 = 6;
    }
    else if (param_2 == 0x11) {
      uVar3 = 4;
    }
    else {
      if (param_2 != 0x12) {
        return 0;
      }
      uVar3 = 5;
    }
    iVar1 = FUN_00403441(uVar3);
    iVar2 = FUN_004ea79e(param_1);
    if (*(short *)(iVar2 + param_2 * 2) < iVar1) {
      return iVar1;
    }
  }
  return 0;
}

