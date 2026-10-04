
undefined4 __thiscall FUN_00452862(int param_1,int param_2,undefined2 *param_3)

{
  char cVar1;
  char cVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  undefined *puVar7;
  undefined4 local_340;
  undefined **local_234 [3];
  undefined1 local_228 [256];
  undefined **local_128;
  undefined4 local_124;
  undefined1 local_11c [256];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = CONCAT22(local_8._2_2_,*param_3);
  if ((*(byte *)(param_3 + 2) == 0xff) || ((*(byte *)(param_3 + 2) & 2) == 0)) {
    sVar3 = *(short *)(param_1 + 0xf0);
  }
  else {
    sVar3 = *(short *)(param_2 + 4);
  }
  local_c = param_1;
  local_10 = FUN_00407498((int)sVar3);
  local_18 = FUN_00401f6f();
  local_1c = FUN_00401f73();
  cVar1 = DAT_006e504c;
  local_14 = *(undefined4 *)(DAT_006e486c + 0x10);
  FUN_0046f824(local_11c,0,0x100);
  local_128 = &PTR_FUN_00666524;
  if (cVar1 != '\0') {
    FUN_00452674(param_2);
    FUN_0046f824(local_228,0,0x100);
    local_234[0] = &PTR_FUN_00666524;
    FUN_0046f847(s_Sound__id_006c41c8,0xffffffff);
    FUN_0046f8e4(local_234);
    FUN_0046fa40((int)(short)local_8);
    FUN_0046f847(&DAT_006c25a8,0xffffffff);
  }
  FUN_00452bb4();
  local_8 = (int)(short)local_8;
  cVar2 = FUN_00582e2a(local_18,local_8);
  if ((cVar2 == '\0') && (cVar2 = FUN_00582e2a(local_1c,local_8), cVar2 == '\0')) {
    if (cVar1 != '\0') {
      FUN_0046f847(s____name_not_found____006c41b0,0xffffffff);
      FUN_004d402a(local_124);
    }
    if (DAT_006f29f4 != '\0') {
      puVar7 = &DAT_006c08dc;
      iVar5 = local_8;
      FUN_005bc69b(s_Sound_failed__kPlaySound__id___006c4190);
      FUN_005bc69b(iVar5);
      FUN_005bc69b(puVar7);
      FUN_00454524(0);
    }
  }
  else {
    if (cVar1 != '\0') {
      FUN_0046f847(s_name_006c4188,0xffffffff);
      FUN_0046f847(local_340,0xffffffff);
      FUN_004d402a(local_124);
      FUN_0046f824(local_228,0,0x100);
      local_234[0] = &PTR_FUN_00666524;
      FUN_0046f847(s_Source__006c417c,0xffffffff);
      FUN_0046f8e4(local_234);
      if (local_10 == 0) {
        puVar7 = &DAT_006c3a10;
      }
      else {
        puVar7 = *(undefined **)(*(int *)(local_10 + 0x11c) + 0x18);
      }
      FUN_0046f847(puVar7,0xffffffff);
      FUN_004d402a(local_124);
    }
    if ((*(char *)(DAT_006e486c + 0x5b) != '\0') &&
       (*(short *)(*(int *)(local_c + 0x118) + 0x12) == 2)) {
      uVar4 = FUN_006359f2(local_c,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor
                           ,0,local_340);
      FUN_004a6ba5(uVar4);
    }
    cVar2 = FUN_0057a7f7(local_340,sVar3);
    if (cVar2 == '\0') {
      if (DAT_006f29f4 != '\0') {
        puVar7 = &DAT_006c08dc;
        pcVar6 = s___name__006c4174;
        iVar5 = local_8;
        FUN_005bc69b(s_Sound_failed__kPlaySound__id___006c4190);
        FUN_005bc69b(iVar5);
        FUN_005bc69b(pcVar6);
        FUN_005bc69b(local_340);
        FUN_005bc69b(puVar7);
        FUN_00454524(0);
      }
      if (cVar1 != '\0') {
        FUN_0046f824(local_228,0,0x100);
        local_234[0] = &PTR_FUN_00666524;
        FUN_0046f847(s_Sound_System_failed_to_Play_006c4154,0xffffffff);
        FUN_0046f8e4(local_234);
        FUN_004d402a(local_124);
      }
    }
  }
  return 1;
}

