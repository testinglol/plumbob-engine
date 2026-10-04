
undefined4 __fastcall FUN_0056ceee(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar2 = FUN_004a69aa();
  if (iVar2 != 0) {
    if (param_1[0x65] != -1) {
      piVar3 = (int *)FUN_004e9744(param_1[0x65]);
      if (piVar3 != (int *)0x0) {
        FUN_0056d067();
        piVar4 = (int *)(**(code **)(*piVar3 + 0x8c))();
        (**(code **)(*piVar4 + 0xac))();
        piVar4 = *(int **)(param_1[0x17] + 0x5c);
        if ((piVar4 != (int *)0x0) && (cVar1 = (**(code **)(*piVar4 + 0x20))(1), cVar1 != '\0')) {
          (**(code **)(*piVar4 + 0x38))(0xffff,param_1 + 7);
          (**(code **)(*piVar4 + 0x24))(1);
        }
        if (param_1[0x77] == 0) {
          iVar5 = (**(code **)(*param_1 + 0xc4))();
          param_1[0x77] = iVar5;
        }
        else {
          cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
          if (cVar1 != '\0') {
            (**(code **)(*(int *)param_1[0x17] + 0x9c))
                      (param_1[0x77],param_1[0x77] + 0x14,param_1 + 7,0);
            (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
          }
        }
        iVar5 = FUN_005ce621(1);
        if (iVar5 == 0) {
          piVar4 = (int *)(**(code **)(*piVar3 + 0x8c))();
          (**(code **)(*piVar4 + 0x50))(0);
          FUN_00463023(param_1 + 0x66);
          uVar6 = FUN_005cee4b();
          FUN_005cee2f(0xffffff);
          piVar3 = (int *)(**(code **)(*piVar3 + 0x8c))();
          uVar7 = (**(code **)(*piVar3 + 0x34))();
          FUN_005a149b(iVar2,uVar7);
          FUN_005cee2f(uVar6);
          FUN_005ce67e();
        }
        (**(code **)(*param_1 + 0x168))();
        return 1;
      }
      param_1[0x65] = 0;
    }
  }
  return 0;
}

