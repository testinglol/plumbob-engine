
uint __fastcall FUN_004cc548(int param_1)

{
  char cVar1;
  uint in_EAX;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined **local_70 [3];
  undefined1 local_64 [64];
  int local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (((*(int *)(param_1 + 0x24) != 1) || (*(int *)(param_1 + 0x28) == 0)) ||
     (in_EAX = FUN_004576f4(), (char)in_EAX == '\0')) {
    return in_EAX & 0xffffff00;
  }
  iVar4 = (int)*(short *)((*(undefined4 **)(param_1 + 0x28))[0x18] + 0x52);
  local_8 = 0;
  local_24 = iVar4;
  cVar1 = FUN_005a55f6(**(undefined4 **)(param_1 + 0x28),iVar4 + 2000,&local_8,4);
  if (cVar1 != '\0') {
    FUN_005a5e48(local_8);
    local_8 = 0;
  }
  cVar1 = FUN_005a55f6(**(undefined4 **)(param_1 + 0x28),iVar4 + 4000,&local_8,4);
  if (cVar1 != '\0') {
    FUN_005a5e48(local_8);
    local_8 = 0;
  }
  if (DAT_006f29ec == '\0') {
    local_1c = param_1 + 0x30;
    cVar1 = FUN_005a5e72();
    if (cVar1 != '\0') {
      local_14 = param_1 + 0x34;
      cVar1 = FUN_005a5e72();
      iVar4 = param_1 + 0x30;
      if (cVar1 != '\0') goto LAB_004cc622;
    }
  }
  local_1c = param_1 + 0x30;
  FUN_005a5e48(0);
  local_14 = param_1 + 0x34;
  FUN_005a5e48(0);
  iVar4 = local_1c;
LAB_004cc622:
  cVar1 = FUN_005a5e72();
  if (cVar1 == '\0') {
    local_c = 0;
    cVar1 = FUN_005a5631(9000,&local_c,4);
    if (cVar1 != '\0') {
      FUN_005a5e48(local_c);
      local_c = 0;
    }
    cVar1 = FUN_005a5631(0x2329,&local_c,4);
    if (cVar1 != '\0') {
      FUN_005a5e48(local_c);
      local_c = 0;
    }
    cVar1 = FUN_005a5e72();
    if ((cVar1 != '\0') && (cVar1 = FUN_005a5e72(), cVar1 != '\0')) {
      FUN_004e5e40(*(undefined4 *)(param_1 + 0x28),iVar4);
    }
    local_10 = 0;
    do {
      cVar1 = FUN_005a5e72();
      if (cVar1 != '\0') {
        piVar2 = (int *)FUN_004096c2();
        cVar1 = (**(code **)(*piVar2 + 0x20))(0x40);
        if (cVar1 != '\0') {
          piVar2 = (int *)FUN_004096c2();
          local_20 = (**(code **)(*piVar2 + 0xcc))();
          piVar2 = (int *)FUN_004096c2();
          uVar3 = (**(code **)(*piVar2 + 0xd0))();
          iVar4 = FUN_004096c2();
          local_18 = *(undefined4 *)(iVar4 + 0x20);
          iVar4 = FUN_004096c2();
          local_18 = FUN_004b7f6b(local_20,uVar3 >> 1,*(undefined4 *)(iVar4 + 0x1c),local_18,0,0);
          piVar2 = (int *)FUN_004096c2();
          (**(code **)(*piVar2 + 0x24))(0x40);
          if (local_18 != 0) {
            FUN_0046f824(local_64,0,0x40);
            local_70[0] = &PTR_FUN_0066651c;
            FUN_0046f847(s_Speech_006c78f8,0xffffffff);
            (**(code **)(*(int *)**(undefined4 **)(param_1 + 0x28) + 0x74))
                      (local_18,0x424d505f,(local_10 + 1) * 2000 + local_24,local_70,1);
            FUN_00401f6f();
            (**(code **)(*(int *)**(undefined4 **)(param_1 + 0x28) + 0x1c))();
            FUN_00401f6f();
            FUN_00465a06(local_18);
            FUN_00401f6f();
          }
        }
      }
      local_10 = local_10 + 1;
    } while (local_10 < 2);
  }
  cVar1 = FUN_005a5e72();
  if ((cVar1 == '\0') || (cVar1 = FUN_005a5e72(), cVar1 == '\0')) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

