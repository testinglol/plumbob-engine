
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e2795(int *param_1,int *param_2,int param_3,char *param_4)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (param_3 == 0) {
    iVar3 = (**(code **)(*param_1 + 0x38))(0x54484d42,0x200,0);
    if (iVar3 == 0) {
      param_2[0x13] = 0x7fffffff;
      param_2[0x14] = 0x7fffffff;
      param_2[0x15] = 0x7fffffff;
      param_2[0x16] = 0x7fffffff;
      param_2[0x17] = 0x7fffffff;
    }
    else {
      _memset(param_2 + 0x13,0,0x14);
      uVar4 = FUN_00420096(iVar3);
      uVar5 = FUN_00420048(iVar3);
      FUN_005a92b0(param_2 + 0x13,uVar5,uVar4);
      FUN_00465a06(iVar3);
    }
    iVar3 = (**(code **)(*param_1 + 0x38))(0x54484d42,0x400,0);
    if (iVar3 != 0) {
      _memset(param_2 + 0x18,0,0x14);
      uVar4 = FUN_00420096(iVar3);
      uVar5 = FUN_00420048(iVar3);
      FUN_005a92b0(param_2 + 0x18,uVar5,uVar4);
      FUN_00465a06(iVar3);
      goto LAB_004e2adc;
    }
LAB_004e2ac8:
    iVar3 = 0x7fffffff;
    param_2[0x18] = 0x7fffffff;
    param_2[0x19] = 0x7fffffff;
    param_2[0x1a] = 0x7fffffff;
    param_2[0x1b] = 0x7fffffff;
  }
  else {
    bVar1 = false;
    if ((undefined4 *)*param_2 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*param_2)(1);
      *param_2 = 0;
    }
    if ((undefined4 *)param_2[1] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_2[1])(1);
      param_2[1] = 0;
    }
    if ((undefined4 *)param_2[2] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_2[2])(1);
      param_2[2] = 0;
    }
    if ((undefined4 *)param_2[3] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_2[3])(1);
      param_2[3] = 0;
    }
    if ((*param_4 == '\x01') && (FUN_005a55f6(param_1,0x400,param_2 + 2,4), param_2[2] != 0)) {
      bVar1 = true;
      *param_4 = '\x01';
      (**(code **)(*(int *)param_2[2] + 0x68))(DAT_006f2a64);
      FUN_005a55f6(param_1,0x401,param_2 + 3,4);
      if ((int *)param_2[3] != (int *)0x0) {
        (**(code **)(*(int *)param_2[3] + 0x68))(DAT_006f2a64);
      }
    }
    else {
      FUN_005a55f6(param_1,0x200,param_2,4);
      if ((int *)*param_2 != (int *)0x0) {
        (**(code **)(*(int *)*param_2 + 0x68))(DAT_006f2a64);
        piVar2 = (int *)FUN_004ba969(_DAT_00666578,*param_2,0,0);
        param_2[2] = (int)piVar2;
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 0x68))(DAT_006f2a64);
        }
      }
      FUN_005a55f6(param_1,0x201,param_2 + 1,4);
      if ((int *)param_2[1] != (int *)0x0) {
        (**(code **)(*(int *)param_2[1] + 0x68))(DAT_006f2a64);
        piVar2 = (int *)FUN_004ba969(_DAT_00666578,param_2[1],0,0);
        param_2[3] = (int)piVar2;
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 0x68))(DAT_006f2a64);
        }
      }
    }
    iVar3 = (**(code **)(*param_1 + 0x38))(0x54484d42,0x200,0);
    if (iVar3 == 0) {
      param_2[0x13] = 0x7fffffff;
      param_2[0x14] = 0x7fffffff;
      param_2[0x15] = 0x7fffffff;
      param_2[0x16] = 0x7fffffff;
      param_2[0x17] = 0x7fffffff;
    }
    else {
      _memset(param_2 + 0x13,0,0x14);
      uVar4 = FUN_00420096(iVar3);
      uVar5 = FUN_00420048(iVar3);
      FUN_005a92b0(param_2 + 0x13,uVar5,uVar4);
      FUN_00465a06(iVar3);
    }
    if (bVar1) {
      uVar4 = 0x400;
    }
    else {
      uVar4 = 0x200;
    }
    iVar3 = (**(code **)(*param_1 + 0x38))(0x54484d42,uVar4,0);
    if (iVar3 == 0) goto LAB_004e2ac8;
    _memset(param_2 + 0x18,0,0x14);
    uVar4 = FUN_00420096(iVar3);
    uVar5 = FUN_00420048(iVar3);
    FUN_005a92b0(param_2 + 0x18,uVar5,uVar4);
    FUN_00465a06(iVar3);
    if (bVar1) goto LAB_004e2adc;
    param_2[0x1a] = param_2[0x1a] / 2;
    param_2[0x18] = param_2[0x18] / 2;
    param_2[0x19] = param_2[0x19] / 2;
    param_2[0x1b] = param_2[0x1b] / 2;
    iVar3 = param_2[0x1c] / 2;
  }
  param_2[0x1c] = iVar3;
LAB_004e2adc:
  FUN_00427f13(param_1,param_2 + 7,param_2 + 5,param_2 + 6,param_2 + 4,param_2 + 8,param_2 + 0x12);
  return;
}

