
undefined4 __fastcall FUN_004cb46e(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  cVar1 = FUN_005a5e72();
  if (cVar1 != '\0') {
    uVar2 = FUN_004096c2(*(undefined1 *)(param_1 + 0x120),param_1 + 0xd8);
    cVar1 = FUN_004cad42(uVar2);
    if (cVar1 != '\0') {
      iVar3 = FUN_004096c2();
      local_18 = *(undefined4 *)(iVar3 + 0x14);
      local_14 = *(undefined4 *)(iVar3 + 0x18);
      local_10 = *(undefined4 *)(iVar3 + 0x1c);
      local_c = *(undefined4 *)(iVar3 + 0x20);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
      local_8 = **(int **)(param_1 + 0x5c);
      uVar2 = FUN_004096c2(&local_18,param_1 + 0x1c,0);
      (**(code **)(local_8 + 0x9c))(uVar2);
      if ((*(char *)(param_1 + 0xf1) != '\0') && (DAT_006f0e84 != 0)) {
        (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))(DAT_006f0e84,&local_18,param_1 + 0x1c,0);
      }
      uVar2 = 0x10;
      iVar3 = **(int **)(param_1 + 0x5c);
      goto LAB_004cb55a;
    }
  }
  cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(1);
  if (cVar1 == '\0') {
    return 1;
  }
  (**(code **)(**(int **)(param_1 + 0x5c) + 0x40))(*(undefined4 *)(param_1 + 100),param_1 + 0x1c,0);
  uVar2 = 1;
  iVar3 = **(int **)(param_1 + 0x5c);
LAB_004cb55a:
  (**(code **)(iVar3 + 0x24))(uVar2);
  return 1;
}

