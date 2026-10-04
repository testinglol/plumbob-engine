
undefined4 __fastcall FUN_005e8eac(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar3 = *(int *)(param_1 + 0x104);
  if (iVar3 == 0) {
    cVar2 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
    if (cVar2 == '\0') goto LAB_005e8f7e;
    (**(code **)(**(int **)(param_1 + 0x5c) + 0xc0))
              (*(undefined4 *)(param_1 + 0xe4),&DAT_006fea48,param_1 + 0x1c,0);
LAB_005e8f74:
    uVar6 = 0x10;
    iVar3 = **(int **)(param_1 + 0x5c);
  }
  else {
    if (iVar3 == 1) {
      cVar2 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
      if (cVar2 == '\0') goto LAB_005e8f7e;
      iVar3 = *(int *)(param_1 + 0xe4);
      local_14 = *(int *)(iVar3 + 0x14);
      local_10 = *(int *)(iVar3 + 0x18);
      local_c = (*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x1c)) + local_14;
      local_8 = (*(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x20)) + local_10;
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))(iVar3,&local_14,param_1 + 0x1c,0);
      goto LAB_005e8f74;
    }
    if ((iVar3 != 2) || (cVar2 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(1), cVar2 == '\0')
       ) goto LAB_005e8f7e;
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x40))
              (*(undefined4 *)(param_1 + 100),param_1 + 0x1c,0);
    uVar6 = 1;
    iVar3 = **(int **)(param_1 + 0x5c);
  }
  (**(code **)(iVar3 + 0x24))(uVar6);
LAB_005e8f7e:
  if (*(int *)(param_1 + 0x104) == 0) {
    iVar4 = FUN_005d49d6();
    iVar3 = DAT_006fea3c;
    if (iVar4 != 0) {
      iVar4 = *(int *)(param_1 + 0x84);
      iVar1 = *(int *)(param_1 + 0x7c);
      iVar5 = (**(code **)(**(int **)(param_1 + 0xdc) + 0x58))();
      local_14 = 0;
      local_8 = iVar3;
      local_10 = (DAT_006fea3c - iVar5) / 2;
      iVar3 = **(int **)(param_1 + 0xdc);
      local_c = iVar4 - iVar1;
      uVar6 = FUN_005d49d6(1);
      uVar6 = FUN_004096c2(uVar6);
      uVar6 = (**(code **)(iVar3 + 0x80))(*(undefined4 *)(param_1 + 0x5c),&local_14,uVar6);
      return uVar6;
    }
  }
  return 1;
}

