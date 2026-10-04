
int * FUN_005c3cd0(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = *(int *)(*param_1 + 4);
  uVar1 = *(uint *)(iVar2 + 8 + (int)param_1);
  if ((uVar1 & 6) != 0) goto LAB_005c3e42;
  if (*(int *)((int)param_1 + iVar2 + 4) == 0) {
    FUN_00596bdf(uVar1 | 4);
    goto LAB_005c3e42;
  }
  if ((*(byte *)((int)param_1 + iVar2 + 0x24) & 1) != 0) {
    do {
      uVar1 = FUN_00634046();
      if (uVar1 == 0xffffffff) goto LAB_005c3d23;
      iVar2 = FUN_00636918(uVar1 & 0xff);
    } while (iVar2 != 0);
    if (uVar1 == 0xffffffff) {
LAB_005c3d23:
      uVar1 = *(uint *)((int)param_1 + *(int *)(*param_1 + 4) + 8) | 3;
    }
    else {
      iVar2 = FUN_005c4410(uVar1);
      if (iVar2 != -1) goto LAB_005c3d52;
      uVar1 = *(uint *)((int)param_1 + *(int *)(*param_1 + 4) + 8) | 2;
    }
    FUN_00596bdf(uVar1);
  }
LAB_005c3d52:
  if (param_1 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*param_1 + 4) + (int)param_1;
  }
  if (((*(byte *)(iVar2 + 8) & 6) == 0) && (iVar2 != 0)) {
    FUN_005c4740();
    iVar2 = *(int *)(*(int *)(*param_1 + 4) + 0x30 + (int)param_1);
    if (iVar2 == 0) {
      iVar2 = -1;
    }
    else {
      FUN_00401674(iVar2);
    }
    while (iVar2 != 0) {
      iVar2 = iVar2 + -1;
      uVar1 = FUN_00634046();
      if (uVar1 == 0xffffffff) {
        uVar1 = *(uint *)((int)param_1 + *(int *)(*param_1 + 4) + 8) | 1;
LAB_005c3e01:
        FUN_00596bdf(uVar1);
        break;
      }
      iVar3 = FUN_00636918(uVar1 & 0xff);
      if (iVar3 != 0) {
        iVar2 = FUN_005c4410(uVar1);
        if (iVar2 == -1) {
          uVar1 = *(uint *)((int)param_1 + *(int *)(*param_1 + 4) + 8) | 2;
          goto LAB_005c3e01;
        }
        break;
      }
      FUN_004015e4(uVar1);
    }
    if (DAT_006fe76c == DAT_006fe768) {
      FUN_00596bdf(*(uint *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) | 2);
    }
  }
  *(undefined4 *)(*(int *)(*param_1 + 4) + 0x30 + (int)param_1) = 0;
LAB_005c3e42:
  uVar4 = FUN_005c4440(param_1,&DAT_006fe758,&DAT_006fe748,&DAT_006fe738,&DAT_006fe718);
  uVar4 = FUN_005c4440(uVar4);
  uVar4 = FUN_005c4440(uVar4);
  FUN_005c4440(uVar4);
  FUN_00634d24(DAT_006fe758,&DAT_006c5518,param_2);
  FUN_00634d24(DAT_006fe748,&DAT_006c5518,param_2 + 4);
  FUN_00634d24(DAT_006fe738,&DAT_006c5518,param_2 + 8);
  return param_1;
}

