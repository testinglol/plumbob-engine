
undefined4 FUN_004b7ecc(int *param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int local_14;
  
  if (param_1 != (int *)0x0) {
    if (param_3 == (int *)0x0) {
      local_14 = param_1[5];
      iVar7 = param_1[6];
      iVar6 = param_1[7];
      iVar2 = param_1[8];
    }
    else {
      local_14 = *param_3;
      iVar7 = param_3[1];
      iVar6 = param_3[2];
      iVar2 = param_3[3];
    }
    cVar1 = (**(code **)(*param_1 + 0x20))(0x40);
    if (cVar1 != '\0') {
      iVar3 = (**(code **)(*param_1 + 0xcc))();
      uVar4 = (**(code **)(*param_1 + 0xd0))();
      uVar5 = FUN_004b7f6b(iVar3 + (iVar7 * (uVar4 >> 1) + local_14) * 2,uVar4 >> 1,iVar6 - local_14
                           ,iVar2 - iVar7,param_2,param_4);
      (**(code **)(*param_1 + 0x24))(0x40);
      return uVar5;
    }
  }
  return 0;
}

