
void __thiscall FUN_00586ed8(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = DAT_006d0438;
  iVar4 = *param_2;
  if (iVar4 != 0) {
    if (((DAT_006f6b80 == '\0') || (param_2 == param_1 + 5)) || (DAT_006d0438 == 0)) {
      (**(code **)(*param_1 + 0xac))(iVar4);
      FUN_005a0903(iVar4);
    }
    else {
      uVar3 = *(undefined4 *)(iVar4 + 0x2c);
      *(undefined4 *)(iVar4 + 0x7c) = 0xffffffff;
      *(undefined4 *)(iVar4 + 0x78) = 0xffffffff;
      uVar1 = (**(code **)(*param_1 + 0x34))(iVar2,uVar3);
      FUN_00597a6c(uVar1,iVar2,uVar3);
      if (param_2 == param_1 + 3) {
        iVar2 = param_1[4];
        if (iVar2 != 0) {
          (**(code **)(*param_1 + 0xac))(iVar2);
          FUN_005a0903(iVar2);
          param_1[4] = 0;
        }
        iVar2 = *(int *)(iVar4 + 0x14);
        param_1[4] = iVar4;
        FUN_00598687(iVar2 + 1);
      }
      else {
        *(undefined4 *)(iVar4 + 100) = 1;
      }
    }
    *param_2 = 0;
  }
  return;
}

