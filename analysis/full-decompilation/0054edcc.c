
undefined4 __fastcall FUN_0054edcc(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  char local_5;
  
  cVar1 = FUN_0054f49c();
  if ((cVar1 == '\0') &&
     (((char)param_1[0x9a] != '\x01' || (cVar1 = FUN_0054f4dd(), cVar1 != '\x01')))) {
    local_5 = '\0';
  }
  else {
    local_5 = '\x01';
  }
  if (((char)param_1[0x8b] == '\0') ||
     ((((char)param_1[0x86] != '\0' && (*(char *)((int)param_1 + 0x219) == '\0')) &&
      (DAT_006e5490 < (uint)param_1[0x8a])))) {
    piVar4 = param_1 + 0x43;
    local_34 = param_1[8];
    local_2c = (param_1[0x46] - param_1[0x44]) + local_34;
    local_38 = param_1[7];
    local_30 = (param_1[0x45] - param_1[0x43]) + local_38;
    iVar2 = param_1[0x41];
    iVar3 = param_1[0x3f];
    cVar1 = FUN_0054f49c();
    if ((cVar1 == '\x01') ||
       (((char)param_1[0x9a] == '\x01' && (cVar1 = FUN_0054f4dd(), cVar1 == '\x01')))) {
      local_18 = 0;
      local_10 = 0;
    }
    else {
      local_10 = param_1[0x3a] * (iVar2 - iVar3);
      local_18 = (uint)(param_1[0x3a] == 0) * (iVar2 - iVar3);
    }
    iVar2 = local_38;
    local_c = 0;
    local_14 = 0;
    local_24 = local_34;
    local_20 = local_30;
    local_28 = local_38;
    local_1c = local_2c;
    FUN_004b469d();
    FUN_004a7901();
    iVar3 = local_28;
    if (((local_28 != iVar2) || (local_20 != local_30)) ||
       ((local_24 != local_34 || (local_1c != local_2c)))) {
      iVar2 = iVar2 - local_28;
      local_14 = local_14 - (local_34 - local_24);
      local_18 = local_18 - iVar2;
      local_10 = local_10 - iVar2;
      local_c = local_c - (local_34 - local_24);
    }
    local_30 = local_20;
    local_34 = local_24;
    local_2c = local_1c;
    FUN_004b469d();
    FUN_004a7901();
    if ((((local_28 != iVar3) || (local_20 != local_30)) || (local_24 != local_34)) ||
       (local_1c != local_2c)) {
      iVar3 = iVar3 - local_28;
      local_14 = local_14 - (local_34 - local_24);
      local_18 = local_18 - iVar3;
      local_10 = local_10 - iVar3;
      local_c = local_c - (local_34 - local_24);
    }
    if ((char)param_1[0x8b] == '\0') {
      FUN_0054f219(&local_28,&local_18,&local_10);
      *(undefined1 *)(param_1 + 0x8b) = 1;
    }
    if ((((char)param_1[0x86] != '\0') && (*(char *)((int)param_1 + 0x219) == '\0')) &&
       (DAT_006e5490 < (uint)param_1[0x8a])) {
      FUN_00473496(DAT_006e5490);
      iVar2 = __ftol();
      if (iVar2 < 0) {
        iVar2 = 0;
      }
      else if (0xff < iVar2) {
        iVar2 = 0xff;
      }
      cVar1 = FUN_0054f49c();
      if ((cVar1 == '\x01') ||
         (((char)param_1[0x9a] == '\x01' && (cVar1 = FUN_0054f4dd(), cVar1 == '\x01')))) {
        if (param_1[0x3a] == 0) {
          iVar5 = param_1[0x36];
          iVar3 = param_1[0x99];
        }
        else {
          iVar5 = param_1[0x99];
          iVar3 = param_1[0x36];
        }
      }
      else {
        iVar3 = param_1[0x36];
        iVar5 = iVar3;
      }
      (*DAT_006f0674)(param_1[0x17],&local_28,iVar3,&local_18,iVar5,&local_10,iVar2);
      (**(code **)(*param_1 + 0x168))();
      return 1;
    }
    if (param_1[0x36] == 0) {
      return 1;
    }
    cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
    if (cVar1 == '\0') {
      return 0;
    }
    local_2c = param_1[0x46] - param_1[0x44];
    local_30 = param_1[0x45] - *piVar4;
    local_38 = 0;
    local_34 = 0;
    FUN_004ba5ac(param_1 + 7);
    FUN_004ba5ac(param_1 + 0x51);
    iVar3 = *(int *)param_1[0x17];
    iVar2 = param_1[0x36];
LAB_0054f1fb:
    (**(code **)(iVar3 + 0x9c))(iVar2,piVar4,&local_38,param_1 + 0x8c);
  }
  else {
    if (param_1[0x36] == 0) {
      return 1;
    }
    cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
    if (cVar1 == '\0') {
      return 0;
    }
    local_24 = param_1[0x44];
    local_30 = param_1[0x43];
    local_20 = param_1[0x45];
    local_1c = param_1[0x46];
    local_28 = local_30;
    if ((*(char *)((int)param_1 + 0x219) != '\0') && (local_30 != 0)) {
      local_28 = local_30 + (local_30 - local_20);
      local_20 = local_20 + (local_30 - local_20);
    }
    local_2c = local_1c - param_1[0x44];
    local_30 = param_1[0x45] - local_30;
    local_38 = 0;
    local_34 = 0;
    FUN_00524f29(param_1[7],param_1[8]);
    FUN_00524f29(param_1[0x51],param_1[0x52]);
    if (local_5 == '\x01') {
      piVar4 = (int *)param_1[0x17];
      if (param_1[0x3a] != 0) {
        iVar2 = param_1[0x99];
        iVar3 = *piVar4;
        piVar4 = (int *)(iVar2 + 0x14);
        goto LAB_0054f1fb;
      }
    }
    else {
      piVar4 = (int *)param_1[0x17];
    }
    (**(code **)(*piVar4 + 0x9c))(param_1[0x36],&local_28,&local_38,param_1 + 0x8c);
  }
  (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
  return 1;
}

