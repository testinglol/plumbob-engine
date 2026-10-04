
undefined4 __fastcall FUN_005e9b13(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(char *)((int)param_1 + 0x105) != '\0') {
    if (param_1[0x42] == 0) {
      iVar2 = (**(code **)(*param_1 + 0xc4))();
      param_1[0x42] = iVar2;
      if (iVar2 == 0) goto LAB_005e9bb0;
    }
    cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
    if (cVar1 != '\0') {
      iVar2 = param_1[0x42];
      local_28 = *(undefined4 *)(iVar2 + 0x14);
      local_24 = *(undefined4 *)(iVar2 + 0x18);
      local_20 = *(undefined4 *)(iVar2 + 0x1c);
      local_1c = *(undefined4 *)(iVar2 + 0x20);
      local_18 = local_28;
      local_14 = local_24;
      local_10 = local_20;
      local_c = local_1c;
      FUN_004ba5ac(param_1 + 7);
      (**(code **)(*(int *)param_1[0x17] + 0x9c))(param_1[0x42],&local_28,&local_18,0);
      (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
    }
  }
LAB_005e9bb0:
  if (param_1[0x36] == 0) {
    return 0;
  }
  cVar1 = (**(code **)(param_1[0x35] + 8))(4);
  if (cVar1 == '\0') {
    if ((param_1[0x16] == 0) ||
       (cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(1), cVar1 == '\0')) goto LAB_005e9c1c;
    iVar2 = *(int *)param_1[0x17];
    iVar5 = param_1[0x3e];
  }
  else {
    cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(1);
    if (cVar1 == '\0') goto LAB_005e9c1c;
    iVar2 = *(int *)param_1[0x17];
    iVar5 = param_1[0x19];
  }
  (**(code **)(iVar2 + 0x38))(iVar5,param_1 + 7);
  (**(code **)(*(int *)param_1[0x17] + 0x24))(1);
LAB_005e9c1c:
  local_8 = (**(code **)(*(int *)param_1[0x36] + 0x1c))();
  if ((char)param_1[0x41] != '\0') {
    (**(code **)(*(int *)param_1[0x36] + 0x20))(param_1[0x3f]);
  }
  iVar2 = *(int *)param_1[0x36];
  uVar3 = FUN_005d49d6(param_1[0x43]);
  uVar3 = FUN_004096c2(uVar3);
  uVar4 = FUN_004df599(&local_28,param_1 + 7);
  (**(code **)(iVar2 + 0x80))(param_1[0x17],uVar4,uVar3);
  if ((char)param_1[0x41] != '\0') {
    (**(code **)(*(int *)param_1[0x36] + 0x20))(local_8);
  }
  return 1;
}

