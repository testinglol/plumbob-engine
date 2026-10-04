
void __thiscall FUN_00592838(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = DAT_006d0438;
  iVar1 = *param_2;
  if (iVar1 != 0) {
    if (((DAT_006f6b80 == '\0') || (param_2 == param_1 + 5)) || (DAT_006d0438 == 0)) {
      FUN_005a0903(iVar1);
    }
    else {
      uVar4 = *(undefined4 *)(iVar1 + 0x2c);
      *(undefined4 *)(iVar1 + 0x7c) = 0xffffffff;
      *(undefined4 *)(iVar1 + 0x78) = 0xffffffff;
      uVar2 = (**(code **)(*param_1 + 0x34))(iVar3,uVar4);
      FUN_00597a6c(uVar2,iVar3,uVar4);
      if (param_2 == param_1 + 3) {
        if (param_1[4] != 0) {
          FUN_005a0903(param_1[4]);
          param_1[4] = 0;
        }
        iVar3 = *(int *)(iVar1 + 0x14);
        param_1[4] = iVar1;
        FUN_00598687(iVar3 + 1);
      }
      else {
        *(undefined4 *)(iVar1 + 100) = 1;
      }
    }
    *param_2 = 0;
  }
  return;
}

