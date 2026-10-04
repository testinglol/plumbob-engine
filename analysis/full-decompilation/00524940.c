
undefined4 __thiscall FUN_00524940(int *param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  if (param_2 == 1) {
    cVar1 = (**(code **)(*param_1 + 0x38))(param_3);
    if (cVar1 != '\0') {
      param_1[0x51] = param_1[0x51] + 1;
      if (param_1[0x51] == 1) {
        iVar2 = FUN_004b46a0();
        iVar3 = (**(code **)(*param_1 + 0x18))();
        if (iVar3 == iVar2) {
          FUN_005dac30(0x10,param_1,*(undefined4 *)(param_3 + 8));
        }
        else {
          uVar6 = *(undefined4 *)(param_3 + 8);
          uVar7 = 0;
          uVar5 = 0x10;
          uVar4 = (**(code **)(*param_1 + 0x18))(0x10,param_1,uVar6,0);
          FUN_005da605(uVar4,uVar5,param_1,uVar6,uVar7);
        }
      }
      return 1;
    }
  }
  else if (param_2 == 0x17) {
    (**(code **)(*param_1 + 0xdc))(0xd,0);
  }
  return 0;
}

