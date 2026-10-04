
undefined4 __fastcall FUN_005f1da2(int *param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  undefined4 uVar9;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_1[0x17] == 0) {
    return 1;
  }
  if (((int *)param_1[0x6d] != (int *)0x0) &&
     ((((char)param_1[0x55] != '\0' || (*(char *)((int)param_1 + 0x155) != '\0')) &&
      (*(char *)((int)param_1 + 0x156) == '\0')))) {
    (**(code **)(*(int *)param_1[0x6d] + 0x10))(500);
    *(undefined1 *)((int)param_1 + 0x156) = 1;
  }
  if (*(char *)((int)param_1 + 0x196) == '\0') {
    if (((int *)param_1[0x17] != (int *)0x0) &&
       (cVar2 = (**(code **)(*(int *)param_1[0x17] + 0x20))(1), cVar2 != '\0')) {
      (**(code **)(*(int *)param_1[0x17] + 0x40))(param_1[0x52],param_1 + 7,0);
      uVar9 = 1;
      iVar3 = *(int *)param_1[0x17];
      goto LAB_005f1e75;
    }
  }
  else {
    if (param_1[0x66] == 0) {
      iVar3 = (**(code **)(*param_1 + 0xc4))();
      param_1[0x66] = iVar3;
      if (iVar3 == 0) goto LAB_005f1e78;
    }
    if (((int *)param_1[0x17] != (int *)0x0) &&
       (cVar2 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10), cVar2 != '\0')) {
      (**(code **)(*(int *)param_1[0x17] + 0x9c))(param_1[0x66],param_1[0x66] + 0x14,param_1 + 7,0);
      uVar9 = 0x10;
      iVar3 = *(int *)param_1[0x17];
LAB_005f1e75:
      (**(code **)(iVar3 + 0x24))(uVar9);
    }
  }
LAB_005f1e78:
  if (param_1[0x39] != 0) {
    local_c = (**(code **)(*(int *)param_1[0x45] + 0x1c))();
    if (*(char *)((int)param_1 + 0x161) != '\0') {
      (**(code **)(*(int *)param_1[0x45] + 0x20))(param_1[0x59]);
    }
    iVar3 = param_1[0x50];
    iVar6 = param_1[0x51];
    local_8 = iVar3;
    piVar4 = (int *)FUN_005d0a09();
    if (param_1 != piVar4) {
      iVar6 = iVar3;
    }
    iVar3 = param_1[0x4b];
    for (iVar7 = iVar3;
        (iVar7 < param_1[0x4c] + iVar3 && (iVar7 < param_1[0x3d] - param_1[0x3c] >> 2));
        iVar7 = iVar7 + 1) {
      bVar8 = iVar7 == iVar3;
      if (iVar7 == param_1[0x4c] + iVar3 + -1) {
        bVar8 = bVar8 | 4;
      }
      if (bVar8 == 0) {
        bVar8 = 2;
      }
      FUN_005f2130(param_1[0x17],param_1 + 7,param_1 + 0x3f,param_1[0x39],param_1[0x45],
                   param_1[0x52],local_8,iVar6,bVar8);
      iVar3 = param_1[0x4b];
    }
    if (*(char *)((int)param_1 + 0x161) != '\0') {
      (**(code **)(*(int *)param_1[0x45] + 0x20))(local_c);
    }
  }
  cVar2 = '\x01';
  if ((char)param_1[0x55] != '\0') {
    cVar2 = (char)param_1[0x57];
  }
  if (param_1[0x4f] == 2) {
    cVar2 = '\0';
  }
  piVar4 = (int *)FUN_005d0a09();
  if (param_1 != piVar4) {
    cVar2 = '\0';
  }
  if ((param_1[0x36] < param_1[0x4b]) || (param_1[0x4c] + param_1[0x4b] <= param_1[0x36])) {
    cVar2 = '\0';
  }
  if (cVar2 != '\0') {
    iVar3 = param_1[0x37];
    iVar6 = param_1[0x3f];
    iVar7 = param_1[0x38] + param_1[0x40];
    local_10 = iVar3 + iVar6;
    local_c = iVar7;
    local_8 = (**(code **)(*(int *)param_1[0x45] + 0x58))();
    if (((int *)param_1[0x17] != (int *)0x0) &&
       (cVar2 = (**(code **)(*(int *)param_1[0x17] + 0x20))(4), cVar2 != '\0')) {
      piVar4 = param_1 + 0x46;
      if (param_1[0x46] <= iVar3 + iVar6) {
        piVar4 = &local_10;
      }
      piVar5 = param_1 + 0x48;
      local_10 = *piVar4;
      if (*piVar4 <= *piVar5) {
        piVar5 = &local_10;
      }
      iVar3 = local_8;
      if (iVar7 < param_1[0x47]) {
        iVar3 = param_1[0x47] - iVar7;
        iVar7 = iVar7 - iVar3;
        iVar3 = local_8 - iVar3;
      }
      if (param_1[0x49] <= iVar7 + iVar3) {
        iVar3 = (param_1[0x49] - iVar7) + -1;
        local_8 = iVar3;
      }
      iVar6 = *piVar5 + param_1[7];
      iVar7 = iVar7 + param_1[8];
      if (((((param_1[7] <= iVar6) && (param_1[8] <= iVar7)) && (iVar6 < param_1[9])) &&
          ((iVar7 < param_1[10] && (iVar1 = iVar3 + -1 + iVar7, param_1[7] <= iVar6)))) &&
         ((param_1[8] <= iVar1 && ((iVar6 < param_1[9] && (iVar1 < param_1[10])))))) {
        (**(code **)(*(int *)param_1[0x17] + 0x80))(iVar6,iVar7,iVar6,iVar3 + iVar7,param_1[0x53],1)
        ;
      }
      (**(code **)(*(int *)param_1[0x17] + 0x24))(4);
    }
  }
  if ((param_1[0x3a] - param_1[0x39] == 1) && (*(char *)((int)param_1 + 0x155) != '\0')) {
    cVar2 = *(char *)((int)param_1 + 0x15d);
  }
  else {
    if ((*(char *)((int)param_1 + 0x15e) == '\0') ||
       (piVar4 = (int *)FUN_005d0a09(), piVar4 != param_1)) goto LAB_005f2115;
    cVar2 = '\x01';
  }
  if ((cVar2 != '\0') && (cVar2 = (**(code **)(*(int *)param_1[0x17] + 0x20))(8), cVar2 != '\0')) {
    (**(code **)(*(int *)param_1[0x17] + 0x50))(param_1 + 7,param_1[0x54],1);
    (**(code **)(*(int *)param_1[0x17] + 0x24))(8);
  }
LAB_005f2115:
  if (*(char *)((int)param_1 + 0x15f) != '\0') {
    (**(code **)(*param_1 + 0x168))();
  }
  return 1;
}

