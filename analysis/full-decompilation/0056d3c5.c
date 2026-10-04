
undefined4 __fastcall FUN_0056d3c5(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 local_34 [40];
  undefined4 local_c;
  int local_8;
  
  local_8 = FUN_004a69aa();
  if ((local_8 == 0) || ((int *)param_1[0x6a] == (int *)0x0)) {
    uVar5 = 0;
  }
  else {
    piVar2 = (int *)(**(code **)(*(int *)param_1[0x6a] + 0x8c))();
    local_c = (**(code **)(*piVar2 + 0xac))();
    piVar2 = *(int **)(param_1[0x17] + 0x5c);
    if (piVar2 != (int *)0x0) {
      cVar1 = (**(code **)(*piVar2 + 0x20))(1);
      if (cVar1 != '\0') {
        (**(code **)(*piVar2 + 0x38))(0xffff,param_1 + 7);
        (**(code **)(*piVar2 + 0x24))(1);
      }
    }
    if (param_1[0x86] == 0) {
      iVar3 = (**(code **)(*param_1 + 0xc4))();
      param_1[0x86] = iVar3;
    }
    else {
      cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
      if (cVar1 != '\0') {
        (**(code **)(*(int *)param_1[0x17] + 0x9c))
                  (param_1[0x86],param_1[0x86] + 0x14,param_1 + 7,0);
        (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
      }
    }
    FUN_004b38e5(local_34);
    uVar8 = 0;
    uVar7 = 0;
    uVar6 = 0;
    uVar5 = 2;
    FUN_00415707(2,0,0,0);
    FUN_0049b248(uVar5,uVar6,uVar7,uVar8);
    FUN_0056d698();
    iVar3 = local_8;
    iVar4 = FUN_005ce621(1);
    if (iVar4 == 0) {
      FUN_0056da1b();
      uVar5 = FUN_005cee4b();
      FUN_005cee2f(0xffffff);
      piVar2 = (int *)(**(code **)(*(int *)param_1[0x6a] + 0x8c))();
      uVar6 = (**(code **)(*piVar2 + 0x34))();
      FUN_005a149b(iVar3,uVar6);
      FUN_005cee2f(uVar5);
      FUN_005ce67e();
    }
    FUN_004b3938(local_34);
    (**(code **)(*param_1 + 0x168))();
    uVar5 = 1;
  }
  return uVar5;
}

