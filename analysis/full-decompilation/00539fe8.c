
undefined4 __fastcall FUN_00539fe8(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int *local_8;
  
  if (*(int **)(param_1 + 0x5c) != (int *)0x0) {
    cVar2 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
    if (cVar2 != '\0') {
      iVar4 = *(int *)(param_1 + 300);
      local_34 = *(int *)(iVar4 + 0x14);
      local_30 = *(undefined4 *)(iVar4 + 0x18);
      local_2c = *(undefined4 *)(iVar4 + 0x1c);
      local_28 = *(undefined4 *)(iVar4 + 0x20);
      local_24 = local_34;
      local_20 = local_30;
      local_1c = local_2c;
      local_18 = local_28;
      FUN_004ba5ac(param_1 + 0x1c);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
                (*(undefined4 *)(param_1 + 300),&local_34,&local_24,0);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
    }
  }
  piVar5 = DAT_006f2a94;
  if (*(int **)(param_1 + 0x20c) != (int *)0x0) {
    piVar5 = *(int **)(param_1 + 0x20c);
  }
  if (piVar5 != (int *)0x0) {
    piVar6 = (int *)(param_1 + 0x170);
    if (*(int *)(param_1 + 0x174) != *piVar6) {
      local_24 = DAT_006f4528;
      local_20 = DAT_006f452c;
      local_1c = DAT_006f4530;
      local_18 = DAT_006f4534;
      local_8 = piVar6;
      FUN_004ba5ac(param_1 + 0x1c);
      local_18 = (**(code **)(*piVar5 + 0x58))();
      local_18 = local_18 + local_20;
      local_c = *piVar5;
      uVar3 = FUN_004096c2(*(int *)(param_1 + 0x174) - *piVar6);
      iVar4 = (**(code **)(local_c + 0x68))(uVar3);
      local_24 = local_24 + ((local_1c - iVar4) - local_24) / 2;
      local_14 = (**(code **)(*piVar5 + 0x1c))();
      cVar2 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
      if (cVar2 != '\0') {
        uVar7 = 0;
        iVar4 = **(int **)(param_1 + 0x5c);
        piVar6 = &local_24;
        uVar3 = FUN_0053a19c(&local_34,param_1 + 0x1c);
        (**(code **)(iVar4 + 0x9c))(*(undefined4 *)(param_1 + 300),uVar3,piVar6,uVar7);
        (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
      }
      (**(code **)(*piVar5 + 0x20))(*(undefined4 *)(param_1 + 0x1a4));
      iVar1 = local_20;
      local_c = local_24;
      local_10 = *(undefined4 *)(param_1 + 0x5c);
      iVar4 = *piVar5;
      uVar3 = FUN_005d49d6(0,0,0);
      uVar3 = FUN_004096c2(uVar3);
      (**(code **)(iVar4 + 0x78))(local_10,local_c,iVar1,uVar3);
      (**(code **)(*piVar5 + 0x20))(local_14);
    }
  }
  return 1;
}

