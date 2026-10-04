
int * __thiscall FUN_005c4440(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int *piVar7;
  char cVar8;
  int local_4;
  
  iVar4 = *(int *)(*param_2 + 4);
  uVar3 = *(uint *)(iVar4 + 8 + (int)param_2);
  if ((uVar3 & 6) != 0) {
    return param_2;
  }
  piVar1 = *(int **)((int)param_2 + iVar4 + 4);
  local_4 = param_1;
  if (piVar1 == (int *)0x0) {
    if (*(int *)((int)param_2 + iVar4 + 0x34) < 0) {
      FUN_00633e5e((int)param_2 + iVar4 + 0x38);
    }
    *(uint *)((int)param_2 + iVar4 + 8) = uVar3 | 4;
    if (*(int *)((int)param_2 + iVar4 + 0x34) < 0) {
      FUN_00633e69((int)param_2 + iVar4 + 0x38);
    }
    return param_2;
  }
  if ((*(byte *)((int)param_2 + iVar4 + 0x24) & 1) != 0) {
    do {
      uVar3 = FUN_00634046();
      if (uVar3 == 0xffffffff) goto LAB_005c449e;
      iVar4 = FUN_00636918(uVar3 & 0xff);
    } while (iVar4 != 0);
    if (uVar3 == 0xffffffff) {
LAB_005c449e:
      iVar5 = *(int *)(*param_2 + 4);
      iVar4 = iVar5 + (int)param_2;
      uVar3 = *(uint *)(iVar5 + 8 + (int)param_2);
      if (*(int *)(iVar5 + 0x34 + (int)param_2) < 0) {
        FUN_00633e5e(iVar4 + 0x38);
      }
      uVar3 = uVar3 | 3;
    }
    else {
      cVar8 = (char)uVar3;
      if ((uint)piVar1[9] < (uint)piVar1[10]) {
        pcVar6 = (char *)(piVar1[10] - 1);
        piVar1[10] = (int)pcVar6;
        *pcVar6 = cVar8;
        iVar4 = (int)cVar8;
      }
      else {
        iVar4 = (**(code **)(*piVar1 + 0x24))((int)cVar8);
      }
      if (iVar4 != -1) goto LAB_005c451b;
      iVar4 = *(int *)(*param_2 + 4) + (int)param_2;
      uVar3 = *(uint *)(iVar4 + 8);
      if (*(int *)(*(int *)(*param_2 + 4) + 0x34 + (int)param_2) < 0) {
        FUN_00633e5e(iVar4 + 0x38);
      }
      uVar3 = uVar3 | 2;
    }
    *(uint *)(iVar4 + 8) = uVar3;
    FUN_005c4720(iVar4);
  }
LAB_005c451b:
  piVar2 = param_3;
  if (param_2 == (int *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(*param_2 + 4) + (int)param_2;
  }
  if (((*(byte *)(iVar4 + 8) & 6) == 0) && (iVar4 != 0)) {
    if ((undefined1 *)*param_3 != (undefined1 *)param_3[1]) {
      *(undefined1 *)*param_3 = 0;
      param_3[1] = *param_3;
    }
    iVar4 = *(int *)(*(int *)(*param_2 + 4) + 0x30 + (int)param_2);
    if (iVar4 == 0) {
      iVar4 = -1;
    }
    else {
      FUN_00401674(iVar4);
    }
    while (iVar4 != 0) {
      iVar4 = iVar4 + -1;
      uVar3 = FUN_00634046();
      if (uVar3 == 0xffffffff) {
        iVar5 = *(int *)(*param_2 + 4);
        uVar3 = *(uint *)(iVar5 + 8 + (int)param_2);
        iVar4 = iVar5 + (int)param_2;
        if (*(int *)(iVar5 + 0x34 + (int)param_2) < 0) {
          FUN_00633e5e(iVar4 + 0x38);
        }
        iVar5 = *(int *)(iVar4 + 0x34);
        *(uint *)(iVar4 + 8) = uVar3 | 1;
joined_r0x005c4626:
        if (iVar5 < 0) {
          FUN_00633e69(iVar4 + 0x38);
        }
        break;
      }
      iVar5 = FUN_00636918(uVar3 & 0xff);
      cVar8 = (char)uVar3;
      if (iVar5 != 0) {
        if ((uint)piVar1[9] < (uint)piVar1[10]) {
          pcVar6 = (char *)(piVar1[10] - 1);
          piVar1[10] = (int)pcVar6;
          *pcVar6 = cVar8;
          iVar4 = (int)cVar8;
        }
        else {
          iVar4 = (**(code **)(*piVar1 + 0x24))((int)cVar8);
        }
        if (iVar4 == -1) {
          iVar5 = *(int *)(*param_2 + 4);
          uVar3 = *(uint *)(iVar5 + 8 + (int)param_2);
          iVar4 = iVar5 + (int)param_2;
          if (*(int *)(iVar5 + 0x34 + (int)param_2) < 0) {
            FUN_00633e5e(iVar4 + 0x38);
          }
          iVar5 = *(int *)(iVar4 + 0x34);
          *(uint *)(iVar4 + 8) = uVar3 | 2;
          goto joined_r0x005c4626;
        }
        break;
      }
      if (piVar2[1] + 1 == piVar2[2]) {
        param_3 = (int *)0x1;
        local_4 = piVar2[1] - *piVar2;
        piVar7 = (int *)&param_3;
        if (local_4 != 0) {
          piVar7 = &local_4;
        }
        FUN_00401674(*piVar7 + local_4);
      }
      FUN_00401651(piVar2[1] + 1);
      *(char *)piVar2[1] = cVar8;
      piVar2[1] = piVar2[1] + 1;
    }
    if (piVar2[1] == *piVar2) {
      iVar4 = *(int *)(*param_2 + 4);
      uVar3 = *(uint *)(iVar4 + 8 + (int)param_2);
      if (*(int *)(iVar4 + 0x34 + (int)param_2) < 0) {
        FUN_00633e5e((int)param_2 + iVar4 + 0x38);
      }
      *(uint *)((int)param_2 + iVar4 + 8) = uVar3 | 2;
      if (*(int *)((int)param_2 + iVar4 + 0x34) < 0) {
        FUN_00633e69((int)param_2 + iVar4 + 0x38);
      }
    }
  }
  *(undefined4 *)(*(int *)(*param_2 + 4) + 0x30 + (int)param_2) = 0;
  return param_2;
}

