
undefined4 __fastcall FUN_005f5c12(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(char *)((int)param_1 + 0x11d) != '\0') {
    if (param_1[0x48] == 0) {
      iVar2 = (**(code **)(*param_1 + 0xc4))();
      param_1[0x48] = iVar2;
      if (iVar2 == 0) goto LAB_005f5cb0;
    }
    cVar1 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
    if (cVar1 != '\0') {
      iVar2 = param_1[0x48];
      local_24 = *(undefined4 *)(iVar2 + 0x14);
      local_20 = *(undefined4 *)(iVar2 + 0x18);
      local_1c = *(undefined4 *)(iVar2 + 0x1c);
      local_18 = *(undefined4 *)(iVar2 + 0x20);
      local_14 = local_24;
      local_10 = local_20;
      local_c = local_1c;
      local_8 = local_18;
      FUN_004ba5ac(param_1 + 7);
      (**(code **)(*(int *)param_1[0x17] + 0x9c))(param_1[0x48],&local_24,&local_14,0);
      (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
    }
  }
LAB_005f5cb0:
  if (param_1[0x42] == 0) {
    FUN_005f5cce();
  }
  else {
    FUN_005f5e36();
  }
  return 1;
}

