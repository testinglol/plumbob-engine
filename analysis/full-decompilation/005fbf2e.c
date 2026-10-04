
uint __thiscall FUN_005fbf2e(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *(uint *)(param_1 + 0xf68);
  if ((int)uVar3 < 1) {
LAB_005fc00a:
    uVar1 = 0;
  }
  else {
    uVar1 = param_3;
    if ((int)uVar3 < (int)param_3) {
      uVar1 = uVar3;
    }
    if (*(short *)(param_1 + 0xf52) == 1) {
      uVar3 = uVar1;
      if (3 < (int)uVar1) {
        uVar4 = uVar1 >> 2;
        iVar2 = param_2 + 2;
        uVar3 = uVar1 + uVar4 * -4;
        do {
          FUN_005fc013(param_2,iVar2);
          param_2 = param_2 + 4;
          iVar2 = iVar2 + 4;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      if (uVar3 == 2) {
        FUN_005fc013(param_2,(int)&param_3 + 2);
      }
    }
    else {
      if (*(short *)(param_1 + 0xf52) != 2) goto LAB_005fc00a;
      uVar3 = uVar1;
      if (7 < (int)uVar1) {
        uVar4 = uVar1 >> 3;
        iVar2 = param_2 + 4;
        uVar3 = uVar1 + uVar4 * -8;
        do {
          FUN_005fc168(param_2,iVar2 + -2,iVar2,iVar2 + 2);
          param_2 = param_2 + 8;
          iVar2 = iVar2 + 8;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      if (uVar3 == 4) {
        FUN_005fc168(param_2,param_2 + 2,(int)&param_3 + 2,(int)&param_3 + 2);
      }
    }
    *(int *)(param_1 + 0xf68) = *(int *)(param_1 + 0xf68) - uVar1;
  }
  return uVar1;
}

