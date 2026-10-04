
void __thiscall
FUN_004aa7fc(int *param_1,undefined4 *param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined1 local_170 [256];
  undefined **local_70;
  undefined4 local_6c;
  undefined1 local_64 [64];
  undefined1 local_24 [16];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_14 = 0x7fffffff;
  local_10 = 0x7fffffff;
  local_c = 0x80000000;
  local_8 = 0x80000000;
  if (*(char *)((int)param_1 + 0x4a) == '\0') {
    bVar3 = false;
    if (*(char *)((int)param_1 + 0x4b) == '\0') {
      if (((char)param_1[0x13] == '\0') && (*(char *)((int)param_1 + 0x4d) == '\0'))
      goto LAB_004aa910;
      goto LAB_004aa836;
    }
  }
  else {
LAB_004aa836:
    bVar3 = *(char *)((int)param_1 + 0x4b) == '\0';
  }
  if ((!bVar3) ||
     (((char)param_1[0x13] != '\0' && (*(short *)(*(int *)(param_3 + 0x118) + 0x12) == 2)))) {
    FUN_00635858(local_170,s__s__d_006c7358,*(undefined4 *)(*(int *)(param_3 + 0x11c) + 0x18),
                 (int)*(short *)(param_3 + 0xf0));
    puVar4 = local_170;
    uVar5 = 4;
    uVar1 = (**(code **)(*param_1 + 0x14))(puVar4,4);
    FUN_004373ae(local_24,param_4,param_5,uVar1,puVar4,uVar5);
    FUN_00422698();
  }
  if ((*(char *)((int)param_1 + 0x4d) != '\0') &&
     ((*(char *)((int)param_1 + 0x4b) != '\0' || (*(short *)(*(int *)(param_3 + 0x118) + 0x12) == 2)
      ))) {
    iVar2 = FUN_00475057();
    if (iVar2 != 0) {
      FUN_0046f824(local_64,0,0x40);
      local_70 = &PTR_FUN_0066651c;
      FUN_004747c8(&local_70);
      uVar5 = 2;
      uVar1 = (**(code **)(*param_1 + 0x14))(local_6c,2);
      FUN_004373ae(local_24,param_4,param_5,uVar1,local_6c,uVar5);
      FUN_00422698();
    }
  }
LAB_004aa910:
  *param_2 = local_14;
  param_2[1] = local_10;
  param_2[2] = local_c;
  param_2[3] = local_8;
  return;
}

